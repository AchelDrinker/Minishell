/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:09:43 by humartin          #+#    #+#             */
/*   Updated: 2022/10/28 15:12:11 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcpylen(char *buff, char *str)
{
	int		i;
	int		ii;
	char	*buff2;

	i = 0;
	ii = 0;
	buff2 = malloc(sizeof(buff - ft_strlen(str)) + 1);
	while (buff[i] == str[i] && (buff[i] != '\0' || str[i] != '\0'))
		i++;
	if (str[0] == 'c' && str[1] == 'd' && str[2] == ' ')
	{
		buff2[ii] = 47;
		ii++;
	}
	while (buff[i] != '\0')
	{
		buff2[ii] = buff[i];
		i++;
		ii++;
	}
	buff2[ii] = '\0';
	return (buff2);
}

void	built_in_cd(char *path, List *environ, char *oldpwd)
{
	int		i;
	int		ii;
	char	*pwd;

	pwd = malloc(10000 * sizeof(char));
	ft_strcpy(pwd, "PWD=");
	ft_strcat(pwd, path);
	i = find_env_pos(environ, "PWD");
	ii = find_env_pos(environ, "OLDPWD");
	if (chdir(path) == 0)
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
	int		i;
	char	*path;
	char	*buff;
	char	*oldpwd;
	char	*lastslash;
	int		count;

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
			ft_strcat(oldpwd,
				ft_strcpylen(getAt(environ,
						find_env_pos(environ, "PWD=")), "PWD="));
			path = ft_strcpylen(line, "cd /");
			built_in_cd(path, environ, oldpwd);
		}
		else
		{
			ft_strcpy(oldpwd, "OLDPWD=");
			ft_strcat(oldpwd,
				ft_strcpylen(getAt(environ,
						find_env_pos(environ, "PWD=")), "PWD="));
			buff = malloc(sizeof(line));
			ft_strcpy(path, getAt(environ, find_env_pos(environ, "PWD=")));
			buff = ft_strcpylen(line, "cd ");
			ft_strcat(path, buff);
			path = ft_strcpylen(path, "PWD=");
			built_in_cd(path, environ, oldpwd);
		}
		return (environ);
	}
	else if (i == 5)
	{
		if (line[5] != '.')
		{
			count = 1;
			ft_strcpy(oldpwd, "OLDPWD=");
			ft_strcat(oldpwd,
				ft_strcpylen(getAt(environ,
						find_env_pos(environ, "PWD=")), "PWD="));
			while (line[i] != '\0' && (line[i] == '/'
					&& line[i + 1] == '.' && line[i + 2] == '.'))
			{
				count += 1;
				i += 3;
			}
			ft_strcpy(path, getAt(environ, find_env_pos(environ, "PWD=")));
			path = ft_strcpylen(path, "PWD=");
			while (count > 0)
			{
				lastslash = ft_strrchr(path, '/');
				ft_bzero(lastslash, ft_strlen(lastslash));
				count--;
			}
			built_in_cd(path, environ, oldpwd);
			return (environ);
		}
		else
		{
			status = 1;
			error_fun();
			ft_putstr_fd("error cd\n", 2);
			return (environ);
		}
	}
	else
		return (environ);
}
