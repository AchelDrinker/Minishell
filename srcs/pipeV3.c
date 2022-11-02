/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeV3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:30:24 by kthierry          #+#    #+#             */
/*   Updated: 2022/11/02 15:34:35 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

pid_t	child1_triple(int fd[2][2], char *parsed_input, t_List *environ)
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
		close(fd[0][0]);
		close(fd[1][0]);
		close(fd[1][1]);
		dup2(fd[0][1], 1);
		close(fd[0][1]);
		check_exec(environ, parsed_input);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

pid_t	child2_triple(int fd[2][2], char *parsed_input, t_List *environ)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		g_status = 127;
		ft_putstr_fd(RED"2nd fork Error"RESET, 2);
		return (1);
	}
	if (pid2 == 0)
	{
		g_status = 0;
		close(fd[0][1]);
		close(fd[1][0]);
		dup2(fd[0][0], 0);
		dup2(fd[1][1], 1);
		close(fd[0][0]);
		close(fd[1][1]);
		check_exec(environ, parsed_input);
		exit(EXIT_FAILURE);
	}
	return (pid2);
}

pid_t	child3_triple(int fd[2][2], char *parsed_input, t_List *environ)
{
	pid_t	pid3;

	pid3 = fork();
	if (pid3 < 0)
	{
		g_status = 127;
		ft_putstr_fd(RED"2nd fork Error"RESET, 2);
		return (1);
	}
	if (pid3 == 0)
	{
		g_status = 0;
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		dup2(fd[1][0], 0);
		close(fd[1][0]);
		check_exec(environ, parsed_input);
		exit(EXIT_FAILURE);
	}
	return (pid3);
}

void	close_pipes(int fd[2][2])
{
	g_status = 0;
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
}

int	pipecreation2(char **parsed_input, t_List *environ)
{
	int		fd[2][2];
	int		i;
	pid_t	pid;
	pid_t	pid2;
	pid_t	pid3;

	i = 0;
	while (i < 2)
	{
		if (pipe(fd[i]) == -1)
		{
			g_status = 127;
			ft_putstr_fd(RED"Pipe Error"RESET, 2);
			return (1);
		}
		i++;
	}
	pid = child1_triple(fd, parsed_input[0], environ);
	pid2 = child2_triple(fd, parsed_input[1], environ);
	pid3 = child3_triple(fd, parsed_input[2], environ);
	close_pipes(fd);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}
