/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:52:00 by humartin          #+#    #+#             */
/*   Updated: 2022/11/14 11:32:13 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	between_quote(const char *line, char *sep)
{
	int	i;

	i = 0;
	if(strchr(line, sep[i]) != NULL)
		i++; <
}


// int	between_quote(const char *line, char *sep)
// {
// 	int	i;
// 	int	z;

// 	i = 0;
// 	z = 0;
// 	while (*line != '\0')
// 	{
// 		printf("%s\n", line);
// 		z = countz(z, line);
// 		if (*line == sep[i] && *line && sep[i] != '\0')
// 		{
// 			if(line++ == sep[i + 1] || sep[i + 1] == '\0')

// 			else
// 				line--;
// 			printf("je suis i : %d\n", i);
// 			i++;
// 		}
// 		printf("je suis le sep[i] : %c\n", sep[i]);
// 		if (z == 0 && sep[i] == '\0')
// 		{
// 			printf("ICI2\n");
// 			return (1);
// 		}
// 		else if (z % 2 == 0 && sep[i] == '\0')
// 			return (0);
// 		else
// 			i = 0;
// 		++line;
// 	}
// 	return (1);
// }

int	check_redirection(char *line, t_List *environ)
{
	char	**parsed_shit;

	if (isredirection(line) == 1)
		return (1);
	else
	{
		printf("ICI3\n");
		parsed_shit = malloc(sizeof(line));
		parsed_shit[0] = line;
		im_parsing_this_shit(parsed_shit, line, environ, 0);
		return (0);
	}
}

int	isredirection(char *line)
{
	// printf("%d\n", between_quote((const char *)line, " << "));
	if (ft_strstr(line, " << ") != 0
		&& between_quote((const char *)line, " << ") != 1)
		return (0);
	else if (ft_strstr(line, " >> ") != 0
		&& between_quote((const char *)line, " >> ") != 1)
		return (0);
	else if (ft_strstr(line, " < ") != 0
		&& between_quote((const char *)line, " < ") != 1)
		return (0);
	else if (ft_strstr(line, " > ") != 0
		&& between_quote((const char *)line, " > ") != 1)
		return (0);
	else
	{
			printf("ICI\n");
		return (1);
	}
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
