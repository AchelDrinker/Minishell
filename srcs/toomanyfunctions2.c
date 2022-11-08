/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:44:12 by humartin          #+#    #+#             */
/*   Updated: 2022/11/08 17:05:10 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	printthis(char *line, int count, int iii, int c)
{
	int	count2;

	count2 = count;
	if (line[c] == iii)
	{
		if (count2 != 2 && count > 1 && count != count2)
			ft_putchar_fd(line[c], 1);
		else
			c++;
		count--;
	}
	else
	{
		ft_putchar_fd(line[c], 1);
		c++;
	}
	return (c);
}

void	ft_echo_n(char *line, int i, t_List *environ)
{
	int		c;
	int		ii;
	char	iii;
	int		count;

	ii = 0;
	c = i;
	iii = 0;
	count = 0;
	if ((line[i] == '$') && echo_env_n(line, ++i, environ, 0) == 0)
		ii = 1;
	if (ii == 0)
	{
		iii = check_iii(line, i, iii);
		count = do_count(line, i, count, iii);
		while (line[c] != '\0')
		{
			c = printthis(line, count, iii, c);
		}
		g_status = 0;
	}
}

void	ft_echo(char *line, int i, t_List *environ)
{
	int		c;
	int		ii;
	char	iii;
	int		count;

	ii = 0;
	c = i;
	iii = 0;
	count = 0;
	if ((line[i] == '$') && echo_env(line, ++i, environ, 0) == 0)
		ii = 1;
	if (ii == 0)
	{
		count = do_count(line, i, count, iii);
		iii = check_iii(line, i, iii);
		while (line[c] != '\0')
		{
			c = printthis(line, count, iii, c);
		}
		write(1, "\n", 1);
		g_status = 0;
	}
}

int	ft_check_quotes(char *line, int i)
{
	int		ii;
	char	iii;
	int		count;

	count = 0;
	ii = i;
	iii = 0;
	iii = check_iii(line, i, iii);
	while (line[ii] != '\0')
	{
		if (line[ii] == iii)
			count++;
		ii++;
	}
	return (count);
}
