/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toomanyfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:45:51 by humartin          #+#    #+#             */
/*   Updated: 2022/11/14 16:12:07 by humartin         ###   ########.fr       */
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
	buff2 = malloc(sizeof(char *) * 10000);
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
	free(buff2);
}

void	built_in_cd(char *path, t_List *environ, char *oldpwd)
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
		setat(environ, oldpwd, ii);
		setat(environ, pwd, i);
		g_status = 0;
	}
	else
	{
		g_status = 1;
		ft_putstr_fd(RED"error chdir\n"RESET, 2);
	}
}

void	ft_error_exit(void)
{
	ft_putstr_fd(RED"exit: too much arg:\n"RESET, 2);
	g_status = 1;
}
