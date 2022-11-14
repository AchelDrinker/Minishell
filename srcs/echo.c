/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:33:02 by humartin          #+#    #+#             */
/*   Updated: 2022/11/10 15:31:17 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	check_iii(char *line, int i, char iii)
{
	while (line[i] != '\0')
	{
		if (line[i] == 34)
		{
			iii = line[i];
			break ;
		}
		else if (line[i] == 39)
		{
			iii = line[i];
			break ;
		}
		else
			i++;
	}
	return (iii);
}

int	do_count(char *line, int i, char iii)
{
	int	count;

	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == iii)
			count++;
		i++;
	}
	return (count);
}

t_List	*do_wo_n(t_List *environ, char *line, int i)
{
	if (ft_check_quotes(line, i) == 1)
	{
		g_status = 1;
		ft_putstr_fd(RED"missing quotes>\n"RESET, 2);
		return (environ);
	}
	else
	{
		g_status = 0;
		if (line[i] == '$' && line[i + 1] == '?')
			return (environ);
		else if (line[i] == 34 && line[i + 1] == 36 && line[i + 2] == 'U'
			&& line[i + 3] == 'S' && line[i + 4] == 'E'
			&& line[i + 5] == 'R' && line[i + 6] == 34)
		{
			ft_echo("echo $USER", i, environ);
			return (environ);
		}
		else
		{
			ft_echo(line, i, environ);
			return (environ);
		}
	}
}

t_List	*do_w_n(t_List *environ, char *line, int i)
{
	if (ft_check_quotes(line, i) == 1)
	{
		g_status = 1;
		ft_putstr_fd(RED"missing quotes>\n"RESET, 2);
		return (environ);
	}
	else
	{
		g_status = 0;
		if (line[i + 1] == '$' && line[i + 2] == '?')
			return (environ);
		ft_echo_n(line, ++i, environ);
		return (environ);
	}
}

t_List	*check_echo(char *line, char *str, char *str2, t_List *environ)
{
	int	i;
	int	c;

	i = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	c = 0;
	while (line[i] == str2[c] && (line[i] != '\0' || str2[c] != '\0'))
	{
		i++;
		c++;
	}
	if (i == 5)
	{
		do_wo_n(environ, line, i);
		return (environ);
	}
	else if (i == 7)
	{
		do_w_n(environ, line, i);
		return (environ);
	}
	else
		return (environ);
}
