/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:07:18 by humartin          #+#    #+#             */
/*   Updated: 2022/11/07 16:47:40 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	county(int quote, const char *s)
{
	if (*s == 34 && quote >= 0)
		quote += 1;
	if (*s == 39 && quote <= 0)
		quote -= 1;
	return(quote);
}

char	**returnstr(char const *s, char c, char **str)
{
	size_t	len;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
			{
				y = county(y, s); //ici ca ne decompte pas les quotes et quand on print, ca affiche 3 caracteres non imprimables
				++s;
			}
			if (y % 2 == 0)
				str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	str[i++] = NULL;
	return (str);
}

char	**parse(char **L, char *line, char c)
{
	int	i;

	i = 0;
	L = ft_split(line, c);
	while (L[i] != NULL)
	{
		if (L[i][0] == ' ')
			L[i] = ft_strcpylen(L[i], " ");
		if (L[i][ft_strlen(L[i]) - 1] == ' ')
			L[i][ft_strlen(L[i]) - 1] = '\0';
		i++;
	}
	return (L);
}
