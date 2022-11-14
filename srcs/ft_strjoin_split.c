/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:51:42 by humartin          #+#    #+#             */
/*   Updated: 2022/11/10 15:09:21 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strcpy_join(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	buff = (char *)malloc(sizeof(char *) * 10000);
	if (buff == NULL)
		return (NULL);
	ft_strcpy_join(buff, s1);
	ft_strcat(buff, s2);
	return (buff);
}

int	ft_splitlen(char const *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++len;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		z;
	int		i;

	i = 0;
	z = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (ft_splitlen(s, c) + 1));
	if (!str)
		return (0);
	if(countfork((char *)s) > 0)
	{
		i = returni(s, c, str, z);
		str = returnstr(s, c, str, z);
		str[i] = NULL;
	}
	else
	{
		str[0] = ft_strdup((char *)s);
		str[1] = NULL;
	}
	return (str);
}
