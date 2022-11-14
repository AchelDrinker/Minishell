/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:54:20 by humartin          #+#    #+#             */
/*   Updated: 2022/11/10 12:57:46 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_List	*check_export2(char *line, int i, int ii, t_List *environ)
{
	int		c;
	char	*line2;

	c = 0;
	line2 = malloc(sizeof(t_Cell));
	i++;
	while (line[i] != '\0')
	{
		if (line[i] == '=')
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
	environ = addat(environ, line2, 1);
	return (environ);
}

t_List	*check_export(char *line, char *str, t_List *environ)
{
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 6)
	{
		if (line[i + 1] != '\0')
		{
			environ = check_export2(line, i, ii, environ);
			return (environ);
		}
		else
		{
			printlist(environ);
			return (environ);
		}
		g_status = 0;
	}
	else
		return (environ);
}

t_List	*ft_unsetenv(t_List *environ, char *line)
{
	int		i;
	t_List	*prec;

	prec = environ;
	i = 0;
	while (ft_strnstr(prec, line, ft_strlen(line)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		i++;
	}
	if (prec->next == NULL)
		return (environ);
	else
	{
		environ = freeat(environ, i);
		return (environ);
	}
}

t_List	check_unset2(char *line, char *line2, int i, t_List *environ)
{
	int	ii;

	ii = 0;
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
		g_status = 0;
		return (*environ);
	}
	else
	{
		g_status = 1;
		ft_putstr_fd(RED"error unset"RESET, 2);
		return (*environ);
	}
}

t_List	*check_unset(char *line, char *str, t_List *environ)
{
	int		i;
	int		ii;
	char	*line2;

	line2 = malloc(sizeof(t_Cell));
	i = 0;
	ii = 0;
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 5)
		check_unset2(line, line2, i, environ);
	free(line2);
	return (environ);
}
