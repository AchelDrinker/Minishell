/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:52:00 by humartin          #+#    #+#             */
/*   Updated: 2022/10/24 16:50:10 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_redirection(char *line, List *environ)
{
	char **parsed_shit;

	if (isRedirection(line) == 1)
		return ;
	else
	{
		parsed_shit = NULL;
		parsed_shit[0] = line;
		imParsingThisShit(parsed_shit, line, environ);
	}
}

int		isRedirection(char *line)
{
	if(ft_strstr(line, "<<") != 0)
		return(0);
	if(ft_strstr(line, ">>") != 0)
		return(0);
	if(ft_strrchr(line, '<') != NULL)
		return(0);
	if(ft_strrchr(line, '>') != NULL)
		return(0);
	else
		return(1);
}

void	imParsingThisShit(char **parsed_shit, char *line, List *environ)
{
	int		i;
	char	**fd;

	i = 0;
	while(parsed_shit[i] != NULL)
	{
		if(ft_strstr(line, "<<") != 0)
		{
			parsed_shit = parse_multiple(parsed_shit, line, "<<");
			fd = ft_split(parsed_shit[1], ' ');
			ft_redi_delimiteur(parsed_shit, fd[0], 0, 0);
			break;
		}
		else if(ft_strstr(line, ">>") != 0)
		{
			parsed_shit = parse_multiple(parsed_shit, line, ">>");
			fd = ft_split(parsed_shit[1], ' ');
			ft_re_app(parsed_shit, fd, environ);
			break;
		}
		else if(ft_strrchr(line, '<') != NULL)
		{
			parsed_shit = parse(parsed_shit, line, '<');
			fd = ft_split(parsed_shit[1], ' ');
			ft_re_in(parsed_shit, fd, environ);
			break;
		}
		else if(ft_strrchr(line, '>') != NULL)
		{
			parsed_shit = parse(parsed_shit, line, '>');
			fd = ft_split(parsed_shit[1], ' ');
			ft_re_out(parsed_shit, fd, environ);
			break;
		}
		i++;
	}
}
