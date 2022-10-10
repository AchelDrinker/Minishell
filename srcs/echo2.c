/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:35:49 by humartin          #+#    #+#             */
/*   Updated: 2022/10/10 18:20:15 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	echo_env_n(char *line, int i, List *environ)
{
	int c;
	List *buff;
	List *prec;
	char *buff2;
	int ii;

	c = 0;
	ii = 0;
	prec = environ;
	buff = emptyList();
	buff2 = malloc(sizeof(line));

	while (line[i] != '\0' && line [i] != ' ')
	{
		buff2[c] = line[i];
		c++;
		i++;
	}
	buff2[c] = '\0';
	while (ft_strnstr(prec, buff2, ft_strlen(buff2)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		ii++;
	}
	if(prec->next == NULL)
	{
		free(buff2);
		return(1);
	}
	else
	{
		buff = addAt(buff, getAt(environ, ii), lenList(buff));
		printCell_n(buff, 0, ft_strlen(buff2));
		free(buff2);
		return (0);
	}
	/*int c;
	List *buff;
	List *prec;
	char *buff2;
	int ii;

	c = 0;
	ii = 0;
	prec = environ;
	buff = emptyList();
	buff2 = malloc(sizeof(line));

	while (line[i] != '\0' && line [i] != ' ')
	{
		buff2[c] = line[i];
		c++;
		i++;
	}
	buff2[c] = '\0';
	while (ft_strnstr(prec, buff2, ft_strlen(line)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		ii++;
	}
	free(buff2);
	if(prec->next == NULL)
		return(1);
	else
	{
		buff = addAt(buff, environ->data, ii);
		c++;
		while(buff->data[c] != '\0')
		{
			printf("%c", buff->data[c]);
			c++;
		}
		return (0);
	}*/
}

int	echo_env(char *line, int i, List *environ)
{
	int c;
	List *buff;
	List *prec;
	char *buff2;
	int ii;

	c = 0;
	ii = 0;
	prec = environ;
	buff = emptyList();
	buff2 = malloc(sizeof(line));

	while (line[i] != '\0' && line [i] != ' ')
	{
		buff2[c] = line[i];
		c++;
		i++;
	}
	buff2[c] = '\0';
	while (ft_strnstr(prec, buff2, ft_strlen(buff2)) == 0 && prec->next != NULL)
	{
		prec = prec->next;
		ii++;
	}
	if(prec->next == NULL)
	{
		free(buff2);
		return(1);
	}
	else
	{
		buff = addAt(buff, getAt(environ, ii), lenList(buff));
		printCell(buff, 0, ft_strlen(buff2));
		free(buff2);
		return (0);
	}
}
