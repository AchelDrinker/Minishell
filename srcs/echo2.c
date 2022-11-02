/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:35:49 by humartin          #+#    #+#             */
/*   Updated: 2022/10/31 12:45:32 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*givebuff2(char *line, int i, int c)
{
	char	*buff2;

	buff2 = malloc(sizeof(line));
	while (line[i] != '\0' && line [i] != ' ')
	{
		buff2[c] = line[i];
		c++;
		i++;
	}
	buff2[c] = '\0';
	return (buff2);
}

int	echo_env_n(char *line, int i, t_List *environ, int ii)
{
	t_List	*buff;
	t_List	*prec;
	char	*buff2;

	prec = environ;
	buff = emptylist();
	buff2 = givebuff2(line, i, 0);
	while (ft_strnstr(prec, buff2, ft_strlen(buff2)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		ii++;
	}
	if (prec->next == NULL)
	{
		free(buff2);
		return (1);
	}
	else
	{
		buff = addat(buff, getat(environ, ii), lenlist(buff));
		printcell_n(buff, 0, ft_strlen(buff2));
		free(buff2);
		return (0);
	}
}

int	echo_env(char *line, int i, t_List *environ, int ii)
{
	t_List	*buff;
	t_List	*prec;
	char	*buff2;

	prec = environ;
	buff = emptylist();
	buff2 = givebuff2(line, i, 0);
	while (ft_strnstr(prec, buff2, ft_strlen(buff2)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		ii++;
	}
	if (prec->next == NULL)
	{
		free(buff2);
		return (1);
	}
	else
	{
		buff = addat(buff, getat(environ, ii), lenlist(buff));
		printcell(buff, 0, ft_strlen(buff2));
		free(buff2);
		return (0);
	}
}
