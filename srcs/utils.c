/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:36:30 by humartin          #+#    #+#             */
/*   Updated: 2022/11/07 14:11:45 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(t_List *dest, t_List *src, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (dest->data[i] != '\0')
		i++;
	j = 0;
	while (src->data[j] != '\0' && j < nb)
	{
		dest->data[i] = src->data[j];
		i++;
		j++;
	}
	dest->data[i] = '\0';
	return (dest->data);
}

char	*ft_strnstr(t_List *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	litlen;

	i = 0;
	litlen = ft_strlen(little);
	if (litlen == 0)
		return ((char *)big);
	if (len != 0)
	{
		while (big->data[i] != '\0' && i <= len - litlen)
		{
			j = 0;
			while (big->data[i + j] == little[j] && little[j] != '\0')
				j++;
			if (j == litlen)
				return ((char *)&big[i]);
			i++;
		}
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
