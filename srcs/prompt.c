/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:01 by humartin          #+#    #+#             */
/*   Updated: 2022/11/07 13:52:10 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_List	*prompt2(char *line, char **parsed_input, t_List *environ, int i)
{
	while (parsed_input[i] != NULL)
	{
		if (countfork(line) > 0)
		{
			if (countfork(line) == 1)
			{
				pipecreation(countfork(line),
					parsed_input, environ);
				break ;
			}
			else
			{
				pipecreation2(parsed_input, environ);
				break ;
			}
		}
		else
		{
			environ = check_input(parsed_input[i], environ);
			i++;
		}
	}
	return (environ);
}

t_List	*prompt_1(char *line, char **parsed_input, t_List *environ, int i)
{
	parsed_input = parse(parsed_input, line, '|');
	check_spe_char(line);
	prompt2(line, parsed_input, environ, i);
	return (environ);
}

t_List	*prompt(char *line, char **parsed_input, t_List *environ, int i)
{
	while (1)
	{
		line = readline("FlexShell$> ");
		if (!line)
			break ;
		add_history(line);
		signal_trap();
		check_exit(line, "exit");
		if (*line != '\0')
			prompt_1(line, parsed_input, environ, i);
	}
	return (environ);
}
