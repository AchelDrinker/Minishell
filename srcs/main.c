/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:04:41 by humartin          #+#    #+#             */
/*   Updated: 2022/10/10 12:25:25 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

List	*check_input(char *line, List *environ)
{
	//check_pipe_quote(line);

	check_path(environ, line);
	environ = check_echo(line, "echo", " -n", environ);
	check_pwd(line, "pwd", environ);
	check_env(line, "env", environ);
	environ = check_export(line, "export", environ);
	environ = check_unset(line, "unset", environ);
	/*check_cd(line, "cd", envp); FAIRE AVEC CHDIR et FORK
	ft_error();*/
	check_exit(line, "exit");
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

	while ((line = readline("minishell> ")) != 0)
	{
		add_history(line);
		signal_trap();
		if (*line != '\0')
		{
			environ = check_input(line, environ);
		}
	}
	environ = freeList(environ);
	return (0);
}
