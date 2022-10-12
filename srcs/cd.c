/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:09:43 by humartin          #+#    #+#             */
/*   Updated: 2022/10/12 18:58:04 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcpylen(char *buff, char *str)
{
	int i;
	int ii;
	int len;
	char *buff2;

	i = 0;
	ii = 0;
	len = ft_strlen(buff);
	buff2 = malloc(sizeof(buff - ft_strlen(str)));
	while(buff[i] == str[i] && (buff[i] != '\0' || str[i] != '\0'))
		i++;
	if(str[0] == 'c' && str[1] == 'd' && str[2] == ' ')
	{
		buff2[ii] = 47;
		ii++;
	}
	while(buff[i] != '\0')
	{
		buff2[ii] = buff[i];
		i++;
		ii++;
	}
	buff2[ii] = '\0';
	return(buff2);
}

void	built_in_cd(char *path, List *environ, char *oldpwd)
{
	int i;
	int ii;
	char *pwd;

	pwd =  malloc(10000 * sizeof(char));
	ft_strcpy(pwd, "PWD=");
	ft_strcat(pwd, path);
	//PWD COMPLET
	i = find_env_pos(environ, "PWD");
	ii = find_env_pos(environ, "OLDPWD");
	if(chdir(path) == 0)
	{
		setAt(environ, oldpwd, ii);
		setAt(environ, pwd, i);
		status = 0;
	}
	else
	{
		status = 1;
		error_fun();
		ft_putstr_fd(" error chdir\n", 2);
	}
}

List	*check_cd(char *line, char *str, List *environ)
{
	int i;
	char *path;
	char *buff;
	char *oldpwd;
	char *lastSlash;

	i = 0;

	oldpwd = malloc(10000 * sizeof(char));
	path = malloc(10000 * sizeof(char));
	while (line[i] == str[i] && (line[i] != '\0' || str[i] != '\0'))
		i++;
	if (i == 3)
	{
		if (line[3] == 47)
		{
			ft_strcpy(oldpwd, "OLDPWD=");
			ft_strcat(oldpwd, ft_strcpylen(getAt(environ, find_env_pos(environ, "PWD=")), "PWD="));
			//OLDPWD COMPLET
			path = ft_strcpylen(line, "cd /");
			//PATH COMPLET
			built_in_cd(path, environ, oldpwd);
		}
		else
		{
			ft_strcpy(oldpwd, "OLDPWD=");
			ft_strcat(oldpwd, ft_strcpylen(getAt(environ, find_env_pos(environ, "PWD=")), "PWD="));
			//OLDPWD COMPLET
			buff = malloc(sizeof(line));
			ft_strcpy(path, getAt(environ, find_env_pos(environ, "PWD=")));
			buff = ft_strcpylen(line, "cd ");
			ft_strcat(path, buff);
			path = ft_strcpylen(path, "PWD=");
			//PATH COMPLET
			built_in_cd(path, environ, oldpwd);
		}
		return(environ);
	}
	else if (i == 5)
	{
		if (line[5] != '.')
		{
			ft_strcpy(oldpwd, "OLDPWD=");
			ft_strcat(oldpwd, ft_strcpylen(getAt(environ, find_env_pos(environ, "PWD=")), "PWD="));
			//OLDPWD COMPLET
			ft_strcpy(path, getAt(environ, find_env_pos(environ, "PWD=")));
			path = ft_strcpylen(path, "PWD=");
			lastSlash = ft_strrchr(path, '/');
			ft_strcpy(lastSlash, "\0");
			//PATH COMPLET
			built_in_cd(path, environ, oldpwd);
			return(environ);
		}
		else
		{
			status = 1;
			error_fun();
			ft_putstr_fd("error cd\n", 2);
			return(environ);
		}
	}
	else
		return(environ);
}
