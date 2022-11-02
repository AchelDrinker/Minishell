/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:37:23 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:36:29 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	editbin(t_List *L, char *line, int i)
{
	while (ft_strnstr(L, line, ft_strlen(line)) == 0 && L->next != NULL)
	{
		L = L->next;
		i++;
	}
	return (i);
}

int	check_pwd(char *line, char *str, t_List *environ)
{
	int	i;

	i = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 3)
	{
		if (line[i] != '\0')
		{
			g_status = 1;
			ft_putstr_fd(RED"pwd: too many arguments\n"RESET, 2);
		}
		else
		{
			g_status = 0;
			echo_env("PWD", 0, environ, 0);
		}
		return (0);
	}
	else
		return (1);
}

int	check_env(char *line, char *str, t_List *environ)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 3)
	{
		setat(environ, "_=/usr/bin/env", editbin(environ, "_=", ii));
		printlist(environ);
		g_status = 0;
		return (0);
	}
	else
		return (1);
}
