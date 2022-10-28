/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:33:02 by humartin          #+#    #+#             */
/*   Updated: 2022/10/28 13:28:32 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

List	*check_echo(char *line, char *str, char *str2, List *environ)
{
	int	i;
	int c;

	i = 0;

	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	c = 0;
	while (line[i] == str2[c] && (line[i] != '\0' || str2[c] != '\0'))
	{
		i++;
		c++;
	}
	if (i == 5)
	{
		if(ft_check_quotes(line, i) == 1)
		{
			status = 1;
			error_fun();
			printf("missing quotes>\n");
			return(environ);
		}
		else
		{
			status = 0;
			if(line[i] == '$' && line[i + 1] == '?')
				return(environ);
			else if(line[i] == 34 && line[i + 1] == 36 && line[i + 2] == 'U' && line[i + 3] == 'S' && line[i + 4] == 'E' && line[i + 5] == 'R' && line[i + 6] == 34)
			{
				ft_echo("echo $USER", i, environ);
				return(environ);
			}
			else
			{
				ft_echo(line, i, environ);
				return(environ);
			}
		}
	}
	else if (i == 7)
	{
		if(ft_check_quotes(line, i) == 1)
		{
			status = 1;
			error_fun();
			printf("missing quotes>\n");
			return(environ);
		}
		else
		{
			status = 0;
			if(line[i + 1] == '$' && line[i + 2] == '?')
				return(environ);
			ft_echo_n(line, ++i, environ);
			return(environ);
		}
	}
	else
		return(environ);
}


void	ft_echo_n(char *line, int i, List *environ)
{
	int c;
	int ii;
	char iii;
	int count;
	int count2;

	ii = 0;
	c = i;
	iii = 0;
	count = 0;
	if ((line[i] == '$') && echo_env_n(line, ++i, environ) == 0)
		ii = 1;
	if (ii == 0)
	{
		while(line[i] != '\0')
		{
			if(line[i] == 34)
			{
				iii = line[i];
				while(line[i] != '\0')
				{
					if (line[i] == iii)
						count++;
					i++;
				}
				break;
			}
			else if (line[i] == 39)
			{
				iii = line[i];
				while(line[i] != '\0')
				{
					if (line[i] == iii)
						count++;
					i++;
				}
				break;
			}
			else
				i++;
		}
		count2 = count;
		while(line[c] != '\0')
		{
			if (line[c] == iii)
			{
				if (count2 != 2 && count > 1 && count != count2)
					ft_putchar_fd(line[c], 1);
				else
					c++;
				count--;
			}
			else
			{
				ft_putchar_fd(line[c], 1);
				c++;
			}
		}
	}
}

void	ft_echo(char *line, int i, List *environ)
{
	int c;
	int ii;
	char iii;
	int count;
	int count2;

	ii = 0;
	c = i;
	iii = 0;
	count = 0;
	if ((line[i] == '$') && echo_env(line, ++i, environ) == 0)
		ii = 1;
	if (ii == 0)
	{
		while(line[i] != '\0')
		{
			if(line[i] == 34)
			{
				iii = line[i];
				while(line[i] != '\0')
				{
					if (line[i] == iii)
						count++;
					i++;
				}
				break;
			}
			else if (line[i] == 39)
			{
				iii = line[i];
				while(line[i] != '\0')
				{
					if (line[i] == iii)
						count++;
					i++;
				}
				break;
			}
			else
				i++;
		}
		count2 = count;
		while(line[c] != '\0')
		{
			if (line[c] == iii)
			{
				if (count2 != 2 && count > 1 && count != count2)
					ft_putchar_fd(line[c], 1);
				else
					c++;
				count--;
			}
			else
			{
				ft_putchar_fd(line[c], 1);
				c++;
			}
		}
		write(1, "\n", 1);
	}
}

int		ft_check_quotes(char *line, int i)
{
	int ii;
	char iii;
	int count;

	count = 0;
	ii = i;
	iii = 0;
	while(line[i] != '\0')
	{
		if(line[i] == 34)
		{
			iii = line[i];
			break;
		}
		else if (line[i] == 39)
		{
			iii = line[i];
			break;
		}
		else
			i++;
	}
	while(line[ii] != '\0')
	{
		if(line[ii] == iii)
			count++;
		ii++;
	}
	return(count);
}
