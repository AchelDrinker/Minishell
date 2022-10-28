/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:05:05 by humartin          #+#    #+#             */
/*   Updated: 2022/10/28 17:06:36 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_exec(List *environ, char *line)
{
	char *line2;
	line2 = "/bin/ls";
	if(strcmp(line, line2) == 0)
		line = " ls";
	char	*path;
	int		count_strings = 0;
	int		count_s = 0;
	path = getAt(environ, find_env_pos(environ, "PATH="));
	char	**split_strings = split_string(path, ":", &count_strings);
	char	**split_line = split_input(line, " /", &count_s);
	exec_com(split_strings, split_line, count_strings);
}

char **split_input(char *string, char *separators, int *count)
{
	//return the lenth of the string PATH
	int len = strlen(string);
	//keep track of the number of substrings to create
	*count = 0;

	int i = 0;
	while (i < len)
	{
		//step thru any separator acure first
		//only to find separator in string if [i] is a character the loop break
		while(i < len)
		{
			if(strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		//old_i is the guard for the case that we dont find any separators
		int old_i = i;
		//next separtor until the end
		//stepping the character that are not separators
		while(i < len)
		{
			if(strchr(separators, string[i]) != NULL)
				break;
			i++;
		}
		//iter the sub string
		if(i > old_i)
			*count = *count + 1;
	}
	//allocation : allocating space for *count amount of pointers to strings
	char **strings = malloc(sizeof(char *) * *count);

	i = 0;
	char buffer[16384];
	int string_index = 0;
	while (i < len)
	{
		//step thru any separator acure first
		//only to find separator in string if [i] is a character the loop break
		while(i < len)
		{
			if(strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		//keep track of wich character of the substring are we at
		int j = 0;
		while(i < len)
		{
			if(strchr(separators, string[i]) != NULL)
				break;
			//copy each character on this substring into buffer
			buffer[j] = string[i];
			i++;
			j++;
		}
		if(j > 0)
		{
			buffer[j] = '\0';
			//to store the string in buffer we need space for the amout of character in the buffer string + '\0' * the amout of space to store the character
			//need to add the char *line to replace the "ls"
			int to_allocate = sizeof(char) * (strlen(buffer) + 1);
			//malloc will allocate enouth space and return a pointer to a block of memory

			//and we gonna have strings at [string_index] store at the adress
			strings[string_index] = malloc(to_allocate);
			strcpy(strings[string_index], buffer);
			string_index++;
		}
	}
	return strings;
	free(strings);
}

char **split_string(char *string, char *separators, int *count)
{
	int len = strlen(string);
	*count = 0;

	int i = 0;
	while (i < len)
	{
		while(i < len)
		{
			if(strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		int old_i = i;
		while(i < len)
		{
			if(strchr(separators, string[i]) != NULL)
				break;
			i++;
		}
		if(i > old_i)
			*count = *count + 1;
	}
	char **strings = malloc(sizeof(char *) * *count);

	i = 0;
	char buffer[16384];
	int string_index = 0;
	while (i < len)
	{
		while(i < len)
		{
			if(strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		int j = 0;
		while(i < len)
		{
			if(strchr(separators, string[i]) != NULL)
				break;
			buffer[j] = string[i];
			i++;
			j++;
		}
		if(j > 0)
		{
			buffer[j] = '\0';
			int to_allocate = sizeof(char) * (strlen(buffer) + 1);
			strings[string_index] = malloc(to_allocate);
			strcpy(strings[string_index], buffer);
			string_index++;
		}
	}
	return strings;
	free(strings); // Ce code n'est jamais exec
}

void	exec_cmd(char **split, char **split_line)
{
	pid_t	pid = 0;
	int		status = 0;

	pid = fork();
	if (pid == -1)
		perror(GREEN"fork"RESET);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		execve(split[0], split_line, NULL);
		exit(EXIT_FAILURE);
	}
}

void	exec_com(char **sp, char **sl, int count)
{
	int i;
	i = 0;
	int j;
	j = 0;
	char *buff;
	char *path_bin;

	while(i < count)
		{
			// char buf[1000];
			char *tmp;
			tmp = ft_strjoin(sp[j], "/");
			buff = ft_strjoin(tmp, sl[0]);
			free(tmp);
			tmp = NULL;
			if (access(buff, F_OK) == 0)
			{
				// printf("buff = %s\n", buf);
				path_bin = buff;
				sl[2] = NULL;//a definir une place
				exec_cmd(&path_bin, &sl[0]/*, count_fork*/);
				break;
			}
			i++;
			j++;
		}
}

void	exec_bin_ls(char **sp, char **sl, int count)
{
		int i;
		i = 0;
		int j;
		j = 0;
		char *buff;
		char *path_bin_ls;
		while(i < count)
		{
			buff = strcat(sp[j], "/");
			strcat(buff, sl[1]);
			if (access(buff, F_OK) == 0)
				break;
			i++;
			j++;
		}
		path_bin_ls = buff;
		sl[2] = NULL;
		exec_cmd(&path_bin_ls, &sl[1]/*, count_fork*/);
		free(buff);
}
