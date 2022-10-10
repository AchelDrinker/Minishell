/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:09:43 by humartin          #+#    #+#             */
/*   Updated: 2022/10/10 21:23:46 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*check_path_cd(List *environ, char *line)
{
	List *prec;
	char *buff;

	prec = environ;
	buff = malloc(sizeof(line));
	while (ft_strnstr(prec, "PATH", ft_strlen("PATH")) == 0 && prec->next != NULL)
		prec = prec->next;
	if(prec->next == NULL)
	{
		free(buff);
		return(NULL);
	}
	else
	{
		buff = prec->data;
		return(buff);
	}
}

char	*check_path_pwd(List *environ, char *line)
{
	List *prec;
	char *buff;

	prec = environ;
	buff = malloc(sizeof(line));
	while (ft_strnstr(prec, "PWD", ft_strlen("PWD")) == 0 && prec->next != NULL)
		prec = prec->next;
	if(prec->next == NULL)
	{
		free(buff);
		return(NULL);
	}
	else
	{
		buff = prec->data;
		return(buff);
	}
}

List	*cd(List *environ, char *path)
{
	char	*oldpwd = NULL;
	char	*pwd = NULL;
	char	*pwd_ptr = NULL;

	if (path == NULL)
		return;
	if (chdir(path) == 0)
	{
		pwd = strrchr(get_env_var("PWD="), '=') + 1;
		oldpwd = strrchr(get_env_var("OLDPWD="), '=') + 1;

		if (oldpwd != NULL && pwd != NULL) {
			strcpy(oldpwd, pwd);
		}
		if (pwd != NULL) {
			pwd = &pwd[-strlen("PWD=")];
			pwd_ptr = built_in_pwd();
			strcpy(pwd, pwd_ptr);
			free(pwd_ptr);
			pwd_ptr = NULL;
		}
	}
	else
	{
		perror("chdir");
	}
}
