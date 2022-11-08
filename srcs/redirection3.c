/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:06:51 by kthierry          #+#    #+#             */
/*   Updated: 2022/11/08 17:08:29 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_while2(int i, char **fd, t_List *environ, char **line)
{
	int		j;
	char	*line2;

	line2 = malloc(sizeof(char *) * 10000);
	j = 0;
	while (j < i)
	{
		line2 = ft_strjoin("echo ", line[j]);
		if (fd != NULL)
			ft_re_app(line2, fd, environ);
		else if (fd == NULL)
			check_input(line2, environ);
		j++;
	}
	free(line2);
}

int	ft_while_i(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i - 1);
}

char	**ft_while(char **line, int i, char *word)
{
	while (1)
	{
		line[i] = readline("heredoc> ");
		if (!ft_check_corresp_word(line[i], word))
			break ;
		i++;
	}
	return (line);
}

void	ft_redi_delimiteur(char **arg, char *word, t_List *environ, char **fd)
{
	char	**line;
	char	**arg2;
	int		i;

	i = 0;
	line = malloc(sizeof(char *) * 10000);
	line = ft_while(line, i, word);
	if (!ft_check_corresp(arg[0], "cat"))
	{
		arg2 = ft_split_exe(arg[1], '>');
		fd = ft_split(arg2[1], ' ');
		i = ft_while_i(line);
		ft_while2(i, fd, environ, line);
		g_status = 0;
	}
	free(line);
}
