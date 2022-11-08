/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:07:18 by humartin          #+#    #+#             */
/*   Updated: 2022/11/08 16:51:44 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	county(int quote, char *s)
{
	if (*s == 34 && quote >= 0)
		quote += 1;
	else if (*s == 39 && quote <= 0)
		quote -= 1;
	return (quote);
}

char	**returnstr(char *s, char c, char **str)
{
	size_t	len;
	int		i;
	int		y;

	i = 0;
	y = 0;
	len = 0;
	while (*s && ++len)
	{
		y = county(y, s);
		++s;
		if (y != 0 && y % 2 == 0 && *s == c)
		{
			str[i] = ft_substr(s - len, 0, len);
			len = 0;
			++s;
			i++;
		}
	}
	if (i == 0)
		str[i] = ft_strdup(s - len);
	str[i + 1] = NULL;
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = (char *) malloc(sizeof(char) * i);
	if (copy == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
