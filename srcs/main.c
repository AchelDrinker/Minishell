/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:04:41 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 12:52:56 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	isbuiltin(char *line)
{
	if (ft_strncmp(line, "cd ", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "export ", 6) == 0)
		return (0);
	else if (ft_strncmp(line, "unset ", 5) == 0)
		return (0);
	else if (ft_strncmp(line, "echo ", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "pwd ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "env ", 3) == 0)
		return (0);
	else
		return (1);
}

t_List	*check_input(char *line, t_List *environ)
{
	if ((isbuiltin(line) == 1) || \
	(isbuiltin(line) == 0 && isredirection(line) == 0))
	{
		check_redirection(line, environ);
		if (isredirection(line) == 1)
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
		environ = check_cd(line, "cd ..", environ, 0);
	}
	return (environ);
}

int	countfork(char *line)
{
	int	i;
	int	countquotes;
	int	countdoublequotes;
	int	countfork;

	countfork = 0;
	countquotes = 0;
	countdoublequotes = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 34)
			countquotes += 1;
		else if (line[i] == 39)
			countdoublequotes += 1;
		else if (line[i] == '|' && countdoublequotes % 2 == 0 \
		&& countquotes % 2 == 0)
			countfork += 1;
		i++;
	}
	return (countfork);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_List	*environ;
	char	**parsed_input;
	int		i;

	(void) argc;
	(void) argv;
	environ = emptylist();
	environ = copyenv(environ, envp);
	line = malloc(sizeof(char *) * 10000);
	parsed_input = NULL;
	i = 0;
	header();
	signal_trap();
	prompt(line, parsed_input, environ, i);
	environ = freelist(environ);
	g_status = 0;
	free(line);
	return (0);
}
