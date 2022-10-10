/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:07 by humartin          #+#    #+#             */
/*   Updated: 2022/10/10 12:24:46 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_path(char *line)
{
	ft_putstr_fd("minishell: command not found:", 2);
	ft_putstr_fd(line, 2);
}

void	check_path(List *environ, char *line)
{
	List *prec;

	prec = environ;
	while (ft_strnstr(prec, "PATH", ft_strlen("PATH")) == 0 && prec->next != NULL)
		prec = prec->next;
	if(prec->next == NULL)
		ft_error_path(line);
}

void	ft_error_echo(char *line)
{
	ft_putstr_fd("erreur echo :", 2);
	ft_putstr_fd(line, 2);
}

void check_exit(char *line, char *s1)
{
	int i;
	i = 0;
	char s2 [] = "'exit'";
	int j;
	j = 0;
	int count;
	count = 0;

	if(ft_strcmp(line, s1) == 0)
		exit(0);
	if(ft_strcmp(line, s2) == 0)
		exit(0);
	if(line[i] == 34)
		i++;
	while(line[i] != 34 && line[i] == s1[j])
	{
		i++;
		j++;
		count++;
	}
	if(count == 4)
		exit(0);
}
