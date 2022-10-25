/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:29:59 by humartin          #+#    #+#             */
/*   Updated: 2022/10/24 16:53:57 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_re_out(char **arg, char **fich, List *environ)
{
	int	fd;
	t_tube	child1;

	fd = open(fich[0], O_RDWR);
	if (fd == -1)
	{
		fd = open(fich[0], O_RDWR | O_CREAT);
		if (fd == -1)
			printf("error\n");
	}
	child1.pid = fork();
	if (child1.pid == 0)
	{
		dup2(fd, 1);
		check_exec(environ, arg[0]);
	}
	waitpid(child1.pid, NULL, 0);
	close(fd);
}

void	ft_re_in(char **arg, char **fich, List *environ)
{
	int	fd;
	t_tube	child1;

	fd = open(fich[0], O_RDWR);
	if (fd == -1)
		printf("no such file or directory:%s\n", arg[1]);
	else
	{
		child1.pid = fork();
		if (child1.pid == 0)
		{
			dup2(fd, 0);
			check_exec(environ, arg[0]);
		}
		waitpid(child1.pid, NULL, 0);
	}
	close(fd);
}

void	ft_re_app(char **arg, char **fich, List *environ)
{
	int	fd;
	t_tube	child1;

	fd = open(fich[0], O_RDWR | O_APPEND);
	if (fd == -1)
	{
		fd = open(fich[0], O_RDWR | O_CREAT);
		if (fd == -1)
			printf("error\n");
	}
	child1.pid = fork();
	if (child1.pid == 0)
	{
		dup2(fd, 1);
		check_exec(environ, arg[0]);
	}
	waitpid(child1.pid, NULL, 0);
	close(fd);
}

int	ft_check_corresp_toutsimple(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_corresp(char *s1, char *s2)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (s2[i])
	{
		check = 0;
		if (s1[j] == ' ' || s1[j] == '\t')
		{
			j++;
			check++;
		}
		if (check == 0)
		{
			if (s1[j] != s2[i])
				return (1);
			j++;
			i++;
		}
	}
	return (0);
}

void	ft_redi_delimiteur(char **arg, char *word, int i, int j)
{
	char	**line;

	line = malloc(sizeof(char *) * 10000);
	while (1)
	{
		line[i] = readline("heredoc> ");
		if (!ft_check_corresp_toutsimple(line[i], word))
			break ;
		i++;
	}
	if (!ft_check_corresp(arg[0], "cat"))
	{
		while (j < i)
		{
			printf("%s\n", line[j]);
			j++;
		}
	}
	free (line);
}

