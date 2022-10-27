/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:20 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 19:03:07 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



List *check_export(char *line, char *str, List *environ)
{
	int i;
	int ii;
	int c;
	char *line2;

	i = 0;
	ii = 0;
	c = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 6)
	{
		if (line[i + 1] != '\0')
		{
			line2 = malloc(sizeof(Cell));
			i++;
			while (line[i] != '\0')
			{
				if(line[i] == '=')
					c = 1;
				line2[ii] = line[i];
				i++;
				ii++;
			}
			if (c == 0)
			{
				line2[ii++] = '=';
				line2[ii++] = '"';
				line2[ii++] = '"';
				line2[ii++] = '\0';
			}
			else
				line2[ii++] = '\0';
			environ = addAt(environ, line2, 0);
			return(environ);
		}
		else
		{
			printList(environ);
			return(environ);
		}
		status = 0;
	}
	else
		return(environ);
}

List *ft_unsetenv(List *environ, char *line)
{
	int i;
	List *prec;

	prec = environ;
	i = 0;
	while (ft_strnstr(prec, line, ft_strlen(line)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		i++;
	}
	if(prec->next == NULL)
		return(environ);
	else
	{
		environ = freeAt(environ, i);
		return(environ);
	}
}

List *check_unset(char *line, char *str, List *environ)
{
	int i;
	int ii;
	char *line2;

	line2 = malloc(sizeof(Cell));

	i = 0;
	ii = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 5)
	{
		i++;
		while (line[i] != '\0')
		{
			line2[ii] = line[i];
			i++;
			ii++;
		}
		line2[ii] = '\0';
		if (ii > 0)
		{
			environ = ft_unsetenv(environ, line2);
			status = 0;
		}
		else
		{
			status = 1;
			error_fun();
			ft_putstr_fd("error unset",2);
			return(environ);
		}
	}
	free(line2);
	return(environ);
}
