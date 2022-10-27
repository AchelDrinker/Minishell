/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:44:04 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 19:11:42 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void check_spe_char(char *line)
{
	int i;
	i = 0;

	while(line[i] != '\0')
	{
		if(line[i] == 92 || line[i] == 59)
		{
			ft_error_char(line, i);
			break;
		}
		i++;
	}
}

void ft_error_char(char *str, int i)
{
	status = 1;
	error_fun();
	printf("wrong character: %c\n", str[i]);
}

int ft_single_quotes(char *line, char *s1)
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	if(line[i] == 34 || line[i] == 39)
		i++;
	while((line[i] != 34 && line[i] != 39) && (line[i] == s1[j]))
	{
		i++;
		j++;
		count++;
	}
	return (count);
}


void	check_status(char *line, char *line2)
{
	if(strcmp(line, line2) == 0)
		printf("Error value : %d\n", status);
	else
		return;
}
