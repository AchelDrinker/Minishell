/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeV2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:56 by humartin          #+#    #+#             */
/*   Updated: 2022/10/27 17:43:59 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int pipeCreation(int countfork, char **parsed_input, List *environ)
{
	int i;
	int fd[2];
	pid_t pid;
	pid_t pid2;
	int status;

	i = 0;
	while(countfork >= 0)
	{
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
			check_exec(environ, parsed_input[countfork]);  // on lance le processus
			close(fd[0]);              //on ferme le read
			printf("Error child1");
			return (1);
		}
		else
		{
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
				check_exec(environ, parsed_input[countfork - 1]);  //on lance le processus
				close(fd[1]);                  // on ferme le write
				printf("Error child2");
				return (1);
			}
			else
			{
			//on est dans le parent2
				while (wait(&status) != pid2);
			}
		}
		countfork--;
	}
	return (0);
}
