/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:07 by humartin          #+#    #+#             */
/*   Updated: 2022/11/07 14:56:23 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_error_path(char *line)
{
	g_status = 127;
	ft_putstr_fd(RED"minishell: command not found:"RESET, 2);
	ft_putstr_fd(line, 2);
	ft_putchar_fd('\n', 2);
}

int	check_path(t_List *environ)
{
	t_List	*prec;

	prec = environ;
	while (ft_strnstr(prec, "PATH", ft_strlen("PATH")) == 0
		&& prec->next != NULL)
		prec = prec->next;
	if (prec->next == NULL)
		return (1);
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
	if (ft_checker_exit(line) <= 1)
	{
		if (ft_checker_exit(line) > 0)
			g_status = 255;
		if (ft_strcmp(line, s1) == 0)
			exit(0);
		while (ft_strcmp(line, s2) == 0)
		{
			break ;
			exit(0);
		}
		while (ft_single_quotes(line, s1) == 4)
			exit(0);
		while (ft_checker_exit(line) >= 1)
		{
			ft_putstr_fd(RED"exit: too much arg:"RESET, 2);
			break ;
		}
	}
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
