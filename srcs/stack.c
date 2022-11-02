/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:04:36 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:36:40 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// create a list
t_List	*emptylist(void)
{
	return (NULL);
}

//check if the list is empty
int	isemptylist(t_List *L)
{
	return (L == NULL);
}

//check and return the lenght of the list
long	lenlist(t_List *L)
{
	long	len;

	len = 0;
	while (L)
	{
		len++;
		L = L->next;
	}
	return (len);
}

//Return the data of an element of the list
char	*getat(t_List *L, int pos)
{
	int	i;

	i = 0;
	if (isemptylist(L))
	{
		g_status = 1;
		printf("error : empty list\n");
		return (NULL);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}

// Copy the environment list in my custom list
t_List	*copyenv(t_List *L, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		L = addat(L, env[i], lenlist(L));
		i++;
	}
	return (L);
}
