/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:04:41 by humartin          #+#    #+#             */
/*   Updated: 2022/10/28 13:18:05 by humartin         ###   ########.fr       */
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

int		countfork(char *line)
{
	int i;
	int countquotes;
	int countdoublequotes;
	int countfork;

	countfork = 0;
	countquotes = 0;
	countdoublequotes = 0;
	i = 0;
	while(line[i] != '\0')
	{
		if (line[i] == 34)
			countquotes += 1;
		else if (line[i] == 39)
			countdoublequotes += 1;
		else if (line[i] == '|' && countdoublequotes % 2 == 0 && countquotes % 2 == 0)
			countfork += 1;
		i++;
	}
	return(countfork);
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

					if (countfork(line) > 0)
					{
						if (countfork(line) == 1)
						{
							pipeCreation(countfork(line), parsed_input, environ);
							break;
						}
						else if (countfork(line) == 2)
						{
							pipeCreation2(parsed_input, environ);
							break;
						}
						else
						{
							ft_putstr_fd(RED"Eh grand, force pas avec les pipes ou on te brise les genoux.\n"RESET, 2);
							break;
						}
					}
					else
					{
						environ = check_input(parsed_input[i], environ);
						i++;
					}
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
