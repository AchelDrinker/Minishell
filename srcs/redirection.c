/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:52:00 by humartin          #+#    #+#             */
/*   Updated: 2022/11/08 17:07:09 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_redirection(char *line, t_List *environ)
{
	char	**parsed_shit;

	if (isredirection(line) == 1)
		return ;
	else
	{
		parsed_shit = malloc(sizeof(line));
		parsed_shit[0] = line;
		im_parsing_this_shit(parsed_shit, line, environ, 0);
	}
}

int	isredirection(char *line)
{
	if (ft_strstr(line, " << ") != 0)
		return (0);
	else if (ft_strstr(line, " >> ") != 0)
		return (0);
	else if (ft_strstr(line, " < ") != 0)
		return (0);
	else if (ft_strstr(line, " > ") != 0)
		return (0);
	else
		return (1);
}

void	im_parsing_this_shit(char **parsed_shit,
char *line, t_List *environ, int i)
{
	while (parsed_shit[i] != NULL)
	{
		if (ft_strstr(line, "<<") != 0)
		{
			parsing_this1(parsed_shit, line, environ);
			break ;
		}
		else if (ft_strstr(line, ">>") != 0)
		{
			parsing_this2(parsed_shit, line, environ);
			break ;
		}
		else if (ft_strrchr(line, '<') != NULL)
		{
			parsing_this3(parsed_shit, line, environ);
			break ;
		}
		else if (ft_strrchr(line, '>') != NULL)
		{
			parsing_this4(parsed_shit, line, environ);
			break ;
		}
		i++;
	}
}
