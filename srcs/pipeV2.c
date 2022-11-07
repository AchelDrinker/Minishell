/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeV2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:41:56 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:33:58 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t	child1(int *fd, char **parsed_input, t_List *environ, int countfork)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		g_status = 127;
		ft_putstr_fd(RED"1st Fork error"RESET, 2);
		return (1);
	}
	if (pid == 0)
	{
		g_status = 0;
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		check_input(parsed_input[countfork], environ);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

pid_t	child2(int *fd, char **parsed_input, t_List *environ, int countfork)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		g_status = 125;
		ft_putstr_fd(RED"2nd fork Error"RESET, 2);
		return (1);
	}
	if (pid2 == 0)
	{
		g_status = 0;
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		check_input(parsed_input[countfork - 1], environ);
		exit(EXIT_FAILURE);
	}
	return (pid2);
}

int	pipecreation(int countfork, char **parsed_input, t_List *environ)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		g_status = 125;
		ft_putstr_fd(RED"Pipe Error"RESET, 2);
		return (1);
	}
	pid = child1(fd, parsed_input, environ, countfork);
	pid2 = child2(fd, parsed_input, environ, countfork);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
