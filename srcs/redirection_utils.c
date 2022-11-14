/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:46:21 by kthierry          #+#    #+#             */
/*   Updated: 2022/11/14 12:39:59 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parsing_this1(char **parsed_shit,
char *line, t_List *environ)
{
	char	**fd;

	fd = NULL;
	parsed_shit = ft_split_exe(line, '<');
	fd = ft_split_exe(parsed_shit[1], ' ');
	ft_redi_delimiteur(parsed_shit, fd[0], environ, fd);
}

void	parsing_this2(char **parsed_shit,
char *line, t_List *environ)
{
	char	**fd;

	fd = NULL;
	parsed_shit = ft_split_exe(line, '>');
	fd = ft_split_exe(parsed_shit[1], ' ');
	ft_re_app(parsed_shit[0], fd, environ);
}

void	parsing_this3(char **parsed_shit,
char *line, t_List *environ)
{
	char	**fd;

	fd = NULL;
	parsed_shit = ft_split_exe(line, '<');
	fd = ft_split_exe(parsed_shit[1], ' ');
	ft_re_in(parsed_shit, fd, environ);
}

void	parsing_this4(char **parsed_shit,
char *line, t_List *environ)
{
	char	**fd;

	fd = NULL;
	parsed_shit = ft_split_exe(line, '>');
	fd = ft_split_exe(parsed_shit[1], ' ');
	ft_re_out(parsed_shit, fd, environ);
}
