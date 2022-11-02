/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_char2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:36:49 by kthierry          #+#    #+#             */
/*   Updated: 2022/10/31 13:02:45 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	printcell_n(t_List *L, int pos, int depart)
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
	printf("%s", str);
}

int	find_env_pos(t_List *environ, char *str)
{
	int		i;
	t_List	*prec;

	prec = environ;
	i = 0;
	while ((ft_strnstr(prec, str, ft_strlen(str)) == 0) && prec != NULL)
	{
		prec = prec->next;
		i++;
	}
	if (prec == NULL)
		return (-1);
	else
		return (i);
}
