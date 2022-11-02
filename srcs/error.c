/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:07 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:36:12 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_path(char *line)
{
	g_status = 1;
	ft_putstr_fd(RED"minishell: command not found:"RESET, 2);
	ft_putstr_fd(line, 2);
	ft_putchar_fd('\n', 2);
}

int	check_path(t_List *environ, char *line)
{
	t_List	*prec;

	prec = environ;
	while (ft_strnstr(prec, "PATH", ft_strlen("PATH")) == 0
		&& prec->next != NULL)
		prec = prec->next;
	if (prec->next == NULL)
	{
		ft_error_path(line);
		return (1);
	}
	else
		return (0);
}

void	ft_error_echo(char *line)
{
	g_status = 1;
	ft_putstr_fd(RED"erreur echo :"RESET, 2);
	ft_putstr_fd(line, 2);
}

void	check_exit(char *line, char *s1)
{
	char	*s2;

	s2 = "'exit'";
	if (ft_checker_exit(line) > 0)
	{
		g_status = 255;
		ft_putstr_fd(RED"exit : command not found\n"RESET, 2);
	}
	else if (ft_strcmp(line, s1) == 0)
		exit(0);
	else if (ft_strcmp(line, s2) == 0)
		exit(0);
	else if (ft_single_quotes(line, s1) == 4)
		exit(0);
}

int	ft_checker_exit(char *line)
{
	int		i;
	int		count;
	char	*substr;

	count = 0;
	i = 0;
	substr = ft_strstr(line, "exit");
	if (!substr)
		return (0);
	while (substr[i] != '\0' && substr[i] != '|')
	{
		if (substr[i] == ' ')
			count += 1;
		i++;
	}
	return (count);
}
