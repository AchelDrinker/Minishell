/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:04:41 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 19:59:42 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

List	*check_input(char *line, List *environ)
{
	//check_pipe_quote(line);
	//check_redirection(line);
	check_status(line, "echo $?");
	environ = check_echo(line, "echo", " -n", environ);
	check_pwd(line, "pwd", environ);
	check_env(line, "env", environ);
	environ = check_export(line, "export", environ);
	environ = check_unset(line, "unset", environ);
	environ = check_cd(line, "cd ..", environ);
	return(environ);
}

int		main(int argc, char **argv, char **envp)
{
	char *line;
	(void)argc;
	(void)argv;

	List *environ;
	environ = emptyList();
	environ = copyEnv(environ, envp);

	header();
	while ((line = readline("minishell> ")) != 0)
	{
		add_history(line);
		signal_trap();
		if (*line != '\0')
		{
			check_exit(line, "exit");
			if (check_path(environ, line) == 0)
			{
				check_spe_char(line);
				environ = check_input(line, environ);
			}
		}
	}
	environ = freeList(environ);
	status = 0;
	return (0);
}
