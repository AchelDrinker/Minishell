/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:17:50 by humartin          #+#    #+#             */
/*   Updated: 2022/10/26 16:48:14 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	ft_child3_bis(List *environ, char *parsed_line, int tube[2][2])
// {
// 	close(tube[0][1]);
// 	close(tube[1][0]);
// 	dup2(tube[0][0], 0);
// 	dup2(tube[1][1], 1);
// 	close(tube[0][0]);
// 	close(tube[1][1]);
// 	check_input(parsed_line, environ);
// 	exit(0);
// }

// void	ft_child2_bis(List *environ, char *parsed_line, int tube[2][2])
// {
// 	close(tube[0][0]);
// 	close(tube[0][1]);
// 	close(tube[1][1]);
// 	dup2(tube[1][0], 0);
// 	close(tube[1][0]);
// 	check_input(parsed_line, environ);
// 	exit(0);
// }


// void	ft_child1_bis(List *environ, char *parsed_line, int tube[2][2])
// {
// 	close(tube[0][0]);
// 	close(tube[1][0]);
// 	close(tube[1][1]);
// 	dup2(tube[0][1], 1);
// 	close(tube[0][1]);
// 	check_input(parsed_line, environ);
// 	exit(0);
// }


// void	check_pipe2(char *line, List *environ, int i)
// {
// 	char	**parsed_line;
// 	t_tube	child1;
// 	t_tube	child2;
// 	t_tube	child3;
// 	int		tube[2][2];

// 	while (i < 2)
// 	{
// 		if(pipe(tube[i]) == -1)
// 		{
// 			status = 127;
// 			error_fun();
// 			ft_putstr_fd("error pipe", 2);
// 		}
// 		i++;
// 	}
// 		i = 0;
// 		parsed_line = ft_split(line, '|');
// 		if(parsed_line[i][0] == ' ')
// 		{
// 			parsed_line[i] = ft_strcpylen(parsed_line[i], " ");
// 		}
// 		child1.pid = fork();
// 		if(child1.pid == 0)
// 			ft_child1_bis(environ, parsed_line[i], tube);
// 		i++;
// 		child3.pid = fork();
// 		if (child3.pid == 0)
// 			ft_child3_bis(environ, parsed_line[i], tube);
// 		i++;
// 		child2.pid = fork();
// 		if (child2.pid == 0)
// 			ft_child2_bis(environ, parsed_line[i], tube);

		//ft_pipe_tmp(program);
// }

