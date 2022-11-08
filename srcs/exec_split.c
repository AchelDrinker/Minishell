/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:38:06 by kthierry          #+#    #+#             */
/*   Updated: 2022/11/08 19:20:51 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_strcount(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != 0)
	{
		if (*s != c && *s)
		{
			len++;
			while (*s != 0 && *s != c)
				s++;
			continue ;
		}
		s++;
	}
	return (len);
}

static char	*ft_alloc_word_by_word(char *s, char c)
{
	int		len;
	char	*ptr;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	ptr = calloc(len + 1, sizeof(char));
	while (*s != c && *s)
		*ptr++ = *s++;
	*ptr = 0;
	return (ptr - len);
}

static void	ft_alloc_all(char *str, char c, int w, char **ptr)
{
	while (*str)
	{
		if (*str != c && *str)
		{
			ptr[w++] = ft_alloc_word_by_word(str, c);
			if (!ptr)
			{
				while (w >= 0)
					free(ptr[w--]);
				free(ptr);
			}
			while (*str != c && *str)
				str++;
			continue ;
		}
		str++;
	}
	ptr[w] = 0;
}

char	**ft_split_exe(char const *s, char c)
{
	int		w;
	char	**ptr;
	char	*str;

	if (!s)
		return (NULL);
	w = 0;
	str = (char *) s;
	ptr = calloc((ft_strcount(str, c) + 1), sizeof(char *));
	ft_alloc_all(str, c, w, ptr);
	return (ptr);
}

void	ft_error_exec2(char *line)
{
	ft_error_path(line);
	g_status = 127;
}
