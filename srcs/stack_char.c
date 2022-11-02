/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:04:36 by humartin          #+#    #+#             */
/*   Updated: 2022/10/31 13:02:13 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_Cell	*createcell(char *data);

//Create a cell with the data in argument
static	t_Cell	*createcell(char *data)
{
	t_Cell	*cell;

	cell = malloc(sizeof(t_Cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

// Add a char element to a defined position of a list
t_List	*addat(t_List *L, char *data, int pos)
{
	t_List	*prec;
	t_List	*cur;
	int		i;
	t_Cell	*cell;

	prec = L;
	cur = L;
	i = 0;
	cell = createcell(data);
	if (isemptylist(L))
		return (cell);
	if (pos == 0)
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
	return (L);
}

//Edit a char element of the list
void	setat(t_List *L, char *data, int pos)
{
	int	i;

	i = 0;
	if (pos > lenlist(L))
		return ;
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}

//print the char list
void	printlist(t_List *L)
{
	while (L)
	{
		printf("%s\n", L->data);
		L = L->next;
	}
}

//print the char cell in argument
void	printcell(t_List *L, int pos, int depart)
{
	int		i;
	int		c;
	char	*str;

	str = malloc(sizeof(t_Cell));
	c = 0;
	i = 0;
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	while (L->data[++depart] != '\0')
	{
		str[c] = L->data[depart];
		c++;
	}
	str[c] = '\0';
	printf("%s\n", str);
}
