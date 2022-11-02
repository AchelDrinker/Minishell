/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:05:05 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:39:39 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_exec(t_List *environ, char *line)
{
	char	*path;
	char	**split_strings;
	char	**split_line;

	path = getat(environ, find_env_pos(environ, "PATH="));
	split_strings = ft_split_exe(path, ':');
	split_line = ft_split_exe(line, ' ');
	if (path != NULL)
	{
		g_status = 0;
		if (ft_strcmp(line, "/bin/ls") == 0)
			exec_bin_ls(split_strings, split_line);
		else
			exec_com(split_strings, split_line, 0, 0);
	}
	else
	{
		g_status = 1;
		perror("path");
	}
}

void	exec_cmd(char **split, char **split_line)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	pid = fork();
	if (pid == -1)
		perror(GREEN"fork"RESET);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		execve(split[0], split_line, NULL);
		exit(EXIT_FAILURE);
	}
}

void	exec_com(char **sp, char **sl, int i, int j)
{
	char	*buff;
	char	*path_bin;
	char	*tmp;

	while (sp != NULL)
	{
		tmp = ft_strjoin(sp[j], "/");
		buff = ft_strjoin(tmp, sl[0]);
		free(tmp);
		if (buff == NULL)
		{
			ft_putstr_fd(RED"command not found\n"RESET, 2);
			g_status = 127;
			break ;
		}
		if (access(buff, F_OK) == 0)
		{
			path_bin = buff;
			sl[2] = NULL;
			exec_cmd(&path_bin, &sl[0]);
			break ;
		}
		i++;
		j++;
	}
}

void	exec_bin_ls(char **sp, char **sl)
{
	int		i;
	int		j;
	char	*buff;
	char	*path_bin_ls;
	char	*tmp;

	i = 0;
	j = 0;
	while (sp != NULL)
	{
		tmp = ft_strjoin(sp[j], "/");
		buff = ft_strjoin(tmp, sl[1]);
		free(tmp);
		if (access(buff, F_OK) == 0)
		{
			path_bin_ls = buff;
			sl[2] = NULL;
			exec_cmd(&path_bin_ls, &sl[1]);
			break ;
		}
		i++;
		j++;
	}
}
