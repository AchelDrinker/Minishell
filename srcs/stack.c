/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:04:36 by humartin          #+#    #+#             */
/*   Updated: 2022/10/11 10:10:15 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// create a list
List	*emptyList(void)
{
	return(NULL);
}

//check if the list is empty
int		isEmptyList(List *L)
{
	return(L == NULL);
}

//check and return the lenght of the list
long	lenList(List *L)
{
	long len;

	len = 0;
	while(L)
	{
		len++;
		L = L->next;
	}
	return(len);
}

//Return the data of an element of the list
char	*getAt(List *L, int pos)
{
	int i;

	i = 0;
	if(isEmptyList(L))
	{
		error_fun();
		printf("error : empty list\n");
		return(NULL);
	}
	while(i < pos)
	{
		i++;
		L = L->next;
	}
	return(L->data);
}

// Copy the environment list in my custom list
List *copyEnv(List *L, char **env)
{
	int i;

	i = 0;
	while(env[i])
	{
		L = addAt(L, env[i], lenList(L));
		i++;
	}
	return(L);
}
