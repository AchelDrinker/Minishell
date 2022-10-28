/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:45:51 by humartin          #+#    #+#             */
/*   Updated: 2022/10/28 16:46:14 by humartin         ###   ########.fr       */
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
