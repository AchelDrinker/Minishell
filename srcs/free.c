/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:32:03 by humartin          #+#    #+#             */
/*   Updated: 2022/10/31 12:48:45 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//free an element of the list
t_List	*freeat(t_List *L, int pos)
{
	t_List	*prec;
	t_List	*cur;
	int		i;

	prec = L;
	cur = L;
	i = 0;
	if (isemptylist(L))
		return (NULL);
	if (pos == 0)
	{
		L = L->next;
		free(cur);
		return (L);
	}
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (L);
}

//free the list
t_List	*freelist(t_List *L)
{
	t_List	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
	return (tmp);
}
