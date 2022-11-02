/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:07:18 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 11:45:30 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	county(int y, const char *s)
{
	if (*s == 39)
		return (y += 1);
	else
		return (y);
}

int	countz(int z, const char *s)
{
	if (*s == 34)
		return (z += 1);
	else
		return (z);
}

int	returni(char const *s, char c, char **str, int z)
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
				z = countz(z, s);
				y = county(y, s);
				++s;
			}
			if (y % 2 == 0 || z % 2 == 0)
				str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	return (i);
}

char	**returnstr(char const *s, char c, char **str, int z)
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
				z = countz(z, s);
				y = county(y, s);
				++s;
			}
			if (y % 2 == 0 || z % 2 == 0)
				str[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
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
