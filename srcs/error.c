/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:07 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 19:32:05 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_path(char *line)
{
	status = 1;
	error_fun();
	ft_putstr_fd("minishell: command not found:", 2);
	ft_putstr_fd(line, 2);
	ft_putchar_fd('\n', 2);
}

int	check_path(List *environ, char *line)
{
	List *prec;

	prec = environ;
	while (ft_strnstr(prec, "PATH", ft_strlen("PATH")) == 0 && prec->next != NULL)
		prec = prec->next;
	if(prec->next == NULL)
	{
		ft_error_path(line);
		return(1);
	}
	else
		return(0);
}

void	ft_error_echo(char *line)
{
	status = 1;
	error_fun();
	ft_putstr_fd("erreur echo :", 2);
	ft_putstr_fd(line, 2);
}

void check_exit(char *line, char *s1)
{
	char s2 [] = "'exit'";

	if((ft_single_quotes(line, s1) == 4 || ft_strcmp(line, s1) == 0 || ft_strcmp(line, s2) == 0) && ft_checker_exit(line) > 1)
	{
		status = 1;
		error_fun();
		ft_putstr_fd("exit : command not found\n", 2);
	}
	else if(ft_strcmp(line, s1) == 0)
		exit(0);
	else if(ft_strcmp(line, s2) == 0)
		exit(0);
	else if(ft_single_quotes(line, s1) == 4)
		exit(0);
}

int ft_checker_exit(char *line)
{
	int i;
	int count;
	count = 0;
	i = 0;

	while(line[i] != '\0')
	{
		if(line[i] == ' ')
		{
			count += 1;
		}
		i++;
	}
	return (count);
}
