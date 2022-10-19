/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:20:59 by humartin          #+#    #+#             */
/*   Updated: 2022/10/19 17:04:55 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
void	ft_close_pipes(int *tube)
{
	close(tube[0]);
	close(tube[1]);
}

void	ft_child2(int *tube, List *environ, char *parsed_line)
{
	dup2(tube[0], 0);
	close(tube[1]);
	check_input(parsed_line, environ);
	exit(0);
}

void	ft_child1(int *tube, List *environ, char *parsed_line)
{
	dup2(tube[1], 1);
	close(tube[0]);
	check_input(parsed_line, environ);
	exit(0);
}

void	check_pipe(char *line, List *environ)
{
	char	**parsed_line;
	t_tube	child1;
	t_tube	child2;
	int		tube[2];

	if (pipe(tube) < 0)
	{
			status = 127;
			error_fun();
			ft_putstr_fd("error pipe", 2);
	}
	parsed_line = ft_split(line, '|');
	if(ft_strcmp(parsed_line[0], line) == 0)
		return;
	printf("%s\n", parsed_line[0]);
	if (parsed_line[2] == NULL)
	{
		if (parsed_line[0][ft_strlen(parsed_line[0]) - 1] == ' ')
			parsed_line[0][ft_strlen(parsed_line[0]) - 1] = '\0';
		printf("%s\n", parsed_line[0]);
		if(parsed_line[1][0] == ' ')
		{
			parsed_line[1] = ft_strcpylen(parsed_line[1], " ");
		}
		child1.pid = fork();
		if (child1.pid == 0)
			ft_child1(tube, environ, parsed_line[0]);
		child2.pid = fork();
		if (child2.pid == 0)
			ft_child2(tube, environ, parsed_line[1]);
		ft_close_pipes(tube);
		waitpid(child1.pid, NULL, 0);
		waitpid(child2.pid, NULL, 0);
		free (parsed_line);
}
	 }
	else
		check_pipe2(line, environ, 0);
}*/


char	**parse(char **L, char *line)
{
	int i;

	i = 0;
	L = ft_split(line, '|');
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
