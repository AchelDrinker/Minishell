/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:09:59 by humartin          #+#    #+#             */
/*   Updated: 2022/10/10 18:19:51 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H__
#define __MINISHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>


typedef struct Cell_t
{
	char			*data;
	struct Cell_t	*next;
}List, Cell;

List	*emptyList(void);
List	*copyEnv(List *, char **);
int		isEmptyList(List *);
long	lenList(List *);
List	*addAt(List *, char *, int);
char	*getAt(List *, int);
void	setAt(List *, char *, int);
List	*freeAt(List *, int);
List	*freeList(List *);
void	printList(List *);
void	printCell(List *, int, int);
void	printCell_n(List *, int, int);
size_t	ft_strlen(const char *);
char	*ft_strncat(List *, List *, int);
char	*ft_strnstr(List *, const char *, size_t);
void	ft_putchar_fd(char, int);
int		echo_env_n(char *, int, List *);
int		echo_env(char *, int, List *);
int		check_echo_env_n(char *, int, List *);
int		check_echo_env(char *, int, List *);
void	ft_echo(char *, int, List *);
void	ft_echo_n(char *, int, List *);
List	*check_echo(char *, char *, char *, List *);
int		check_pwd(char *, char *, List *);
int		check_env (char *, char *, List *);
List	*check_input(char *, List *);
List	*check_export(char *, char *, List *);
List	*ft_unsetenv(List *, char *);
List	*check_unset(char *, char *, List *);
void	check_path(List *, char *);
void	ft_error_path(char *);
void	ft_putstr_fd(char *, int);
void	ft_error_echo(char *);
void	signal_trap(void);
void	signal_exec(void);
void	handle_exec(int);
void	handle_shell(int);
void	check_exit(char *, char *);
int		ft_strcmp(char *, char *);
int		ft_check_quotes(char *, int);

#endif
