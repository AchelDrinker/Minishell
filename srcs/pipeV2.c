/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeV2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:56 by humartin          #+#    #+#             */
/*   Updated: 2022/10/27 18:36:59 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int pipeCreation(int countfork, char **parsed_input, List *environ)
{
	int fd[2];
	pid_t pid;
	pid_t pid2;


	// while(countfork >= 0)
	// {
		if (pipe(fd) == -1)
		{
			printf("Pipe Error");
			return (1);
		}
		//creation du fils
		if ((pid = fork()) < 0)
		{
			printf("1st Fork error");
			return (1);
		}
		if (pid == 0)
		{
		//on est dans le fils1
			close(fd[1]);               // on ferme le write
			dup2(fd[0], 0);             // on redirige l'entrée sur fd[0]
			close(fd[1]);              //on ferme le read
			check_exec(environ, parsed_input[countfork]);  // on lance le processus
			exit(EXIT_FAILURE);
		}



		//on est dans le parent1
			if ((pid2 = fork()) < 0)
			{        //fork pour ne pas sortir du minishell
				printf("2nd fork Error");
				return (1);
			}
			if (pid2 == 0)
			{
			// on est dans le fils2
				close(fd[0]);               //on ferme le read
				dup2(fd[1], 1);             //on redirige la sortie sur fd[1]
				close(fd[0]);                  // on ferme le write
				check_exec(environ, parsed_input[countfork - 1]);  //on lance le processus
				exit(EXIT_FAILURE);
			}
			close(fd[1]);                  // on ferme le write
			close(fd[0]);                  // on ferme le read
			waitpid(pid, NULL, 0);
			waitpid(pid2, NULL, 0);
			// else
			// {
			// //on est dans le parent2
			// 	while (wait(&status) != pid2);
			// }

	// 	countfork--;
	// }
	return (0);
}


char	**parse(char **L, char *line, char c)
{
	int i;

	i = 0;
	L = ft_split(line, c);
	while(L[i] != NULL)
	{
		if (L[i][0] == ' ')
			L[i] = ft_strcpylen(L[i], " ");
		if(L[i][ft_strlen(L[i]) - 1] == ' ')
			L[i][ft_strlen(L[i]) - 1] = '\0';
		i++;
	}
	return(L);
}
