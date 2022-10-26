/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:29:59 by humartin          #+#    #+#             */
/*   Updated: 2022/10/26 16:52:40 by humartin         ###   ########.fr       */
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
		check_input(arg[0], environ);
		exit(EXIT_FAILURE);
	}
	waitpid(child1.pid, NULL, 0);
	close(fd);
}

void	ft_re_in(char **arg, char **fich, List *environ)
{
	int	fd;
	t_tube	child1;

	fd = open(fich[0], O_RDWR);
	child1.pid = fork();
	if (child1.pid == 0)
	{
		dup2(fd, 0);
		check_exec(environ, arg[0]);
		exit(EXIT_FAILURE);
	}
	waitpid(child1.pid, NULL, 0);
	close(fd);
}

void	ft_re_app(char *arg, char **fich, List *environ)
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
		check_input(arg, environ);
		exit(EXIT_FAILURE);
	}
	waitpid(child1.pid, NULL, 0);
	close(fd);
}

int	ft_check_corresp_word(char *s1, char *s2)
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

void	ft_redi_delimiteur(char **arg, char *word, int i, int j, List *environ, char **fd)
{
	char	**line;
	char	*line2;
	char	**arg2;
	int		count;

	count = 0;
	line = malloc(sizeof(char *) * 10000);
	line2 = malloc(sizeof(char *) * 10000);
	while (1)
	{
		line[i] = readline("heredoc> ");
		if (!ft_check_corresp_word(line[i], word))
			break ;
		i++;
	}
	if (!ft_check_corresp(arg[0], "cat"))
	{
		arg2 = split_input(arg[1], ">", &count);
		fd = ft_split(arg2[1], ' ');
		while (j < i)
		{
			line2 = ft_strjoin("echo ", line[j]);
			ft_re_app(line2, fd, environ);

			j++;
		}
	}
	free(line);
	free(line2);
}
