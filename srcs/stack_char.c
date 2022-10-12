/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:04:36 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 19:07:21 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static Cell *createCell(char *);

//Create a cell with the data in argument
static Cell *createCell(char *data)
{
	Cell *cell;

	cell = malloc(sizeof(Cell));
	if (!cell)
		return NULL;
	cell->data = data;
	cell->next = NULL;
	return(cell);
}

// Add a char element to a defined position of a list
List	*addAt(List *L, char *data, int pos)
{
	List *prec;
	List *cur;
	int i;

	prec = L;
	cur = L;
	i = 0;
	Cell *cell = createCell(data);
	if (isEmptyList(L))
	{
		return(cell);
	}
	if(pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return(L);
}

//Edit a char element of the list
void	setAt(List *L, char *data, int pos)
{
	int i;

	i = 0;
	if(pos > lenList(L))
		return;
	while(i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}

//print the char list
void	printList(List *L)
{
	while(L)
	{
		printf("%s\n", L->data);
		L = L->next;
	}
}

//print the char cell in argument
void	printCell(List *L, int pos, int depart)
{
	int i;
	int c;
	char *str;

	str = malloc(sizeof(Cell));
	c = 0;
	i = 0;
	while(i < pos)
	{
		i++;
		L = L->next;
	}
	while(L->data[++depart] != '\0')
	{
		str[c] = L->data[depart];
		c++;
	}
	str[c] = '\0';
	printf("%s\n", str);
}

void	printCell_n(List *L, int pos, int depart)
{
	int i;
	int c;
	char *str;

	str = malloc(sizeof(Cell));
	c = 0;
	i = 0;
	while(i < pos)
	{
		i++;
		L = L->next;
	}
	while(L->data[++depart] != '\0')
	{
		str[c] = L->data[depart];
		c++;
	}
	str[c] = '\0';
	printf("%s", str);
}

int		find_env_pos(List *environ, char *str)
{
	int i;
	List *prec;

	prec = environ;
	i = 0;
	while ((ft_strnstr(prec, str, ft_strlen(str)) == 0) && prec != NULL)
	{
		prec = prec->next;
		i++;
	}
	if (prec == NULL)
		return(-1);
	else
		return(i);
}
