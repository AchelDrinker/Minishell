/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:37:23 by humartin          #+#    #+#             */
/*   Updated: 2022/10/24 13:41:16 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	editBin(List *L, char *line, int i)
		{
			while (ft_strnstr(L, line, ft_strlen(line)) == 0 && L->next != NULL)
			{
				L = L->next;
				i++;
			}
			return(i);
		}

int	check_pwd(char *line, char *str, List *environ)
{
	int i;

	i = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 3)
	{
		if(line[i] != '\0')
		{
			status = 1;
			error_fun();
			ft_putstr_fd("pwd: too many arguments\n", 2);
		}
		else
			echo_env("PWD", 0, environ);
		return(0);
	}
	else
		return(1);
}

int	check_env (char *line, char *str, List *environ)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 3)
	{
		setAt(environ, "_=/usr/bin/env", editBin(environ, "_=", ii));
		printList(environ);
		status = 0;
		return(0);
	}
	else
		return(1);
}
