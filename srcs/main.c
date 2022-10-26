/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:04:41 by humartin          #+#    #+#             */
/*   Updated: 2022/10/26 16:58:31 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		isbuiltin(char *line)
{
	if(strncmp(line, "cd ", 2) == 0)
		return(0);
	else if(strncmp(line, "export ", 6) == 0)
		return(0);
	else if(strncmp(line, "unset ", 5) == 0)
		return(0);
	else if(strncmp(line, "echo ", 4) == 0)
		return(0);
	else if(strncmp(line, "pwd ", 3) == 0)
		return(0);
	else if(strncmp(line, "env ", 3) == 0)
		return(0);
	else
		return(1);

}

List	*check_input(char *line, List *environ)
{
	if((isbuiltin(line) == 1) || (isbuiltin(line) == 0 && isRedirection(line) == 0))
	{
		check_redirection(line, environ);
		if (isRedirection(line) == 1)
			check_exec(environ, line);
	}
	else
	{
		check_status(line, "echo $?");
		environ = check_echo(line, "echo", " -n", environ);
		check_pwd(line, "pwd", environ);
		check_env(line, "env", environ);
		environ = check_export(line, "export", environ);
		environ = check_unset(line, "unset", environ);
		environ = check_cd(line, "cd ..", environ);
	}
	return(environ);
}

int		main(int argc, char **argv, char **envp)
{
	char *line;
	(void)argc;
	(void)argv;
	int count;

	List *environ;
	char **parsed_input;
	int i;
	count = 0;

	environ = emptyList();
	environ = copyEnv(environ, envp);
	i = 0;

	header();
	signal_trap();
	while ((line = readline("FlexShell> ")) != 0)
	{
		add_history(line);
		signal_trap();
		if (*line != '\0')
		{
			check_exit(line, "exit");
			parsed_input = parse(parsed_input, line, '|');
			if (check_path(environ, line) == 0)
			{
				check_spe_char(line);
				while(parsed_input[i] != NULL)
				{
					environ = check_input(parsed_input[i], environ);
					i++;
				}
			}
			i = 0;
		}
	}
	environ = freeList(environ);
	status = 0;
	free(line);
	return (0);
}
