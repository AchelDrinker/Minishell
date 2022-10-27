/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:09:59 by humartin          #+#    #+#             */
/*   Updated: 2022/10/27 16:58:54 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H__
#define __MINISHELL_H__
#define GREEN			"\x1b[32m"
#define RESET			"\x1b[0m"
#define RED				"\033[91m"

#define F_OK 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>


int		status;


typedef struct s_tube
{
	pid_t	pid;
}t_tube;

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
int		check_path(List *, char *);
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
int		ft_checker_exit(char *);
void	ft_error_char(char *, int);
void	check_spe_char(char *);
int		ft_single_quotes(char *, char *);
void	error_fun(void);
void	header(void);
List	*check_cd(char *, char *, List *);
char	*ft_strcpylen(char *, char *);
int		ft_strncmp(const char *, const char *, size_t);
char	*ft_strrchr(const char *, int);
char	*ft_strcpy(char *, char *);
char	*ft_strcat(char *, const char *);
int		find_env_pos(List *, char *);
void	check_status(char *, char *);
char	*ft_strstr(char *, char *);
char	**ft_split(char const *, char);
int		ft_splitlen(char const *, char);
void	check_pipe(char *, List *);
void	check_pipe2(char *, List *, int);
char	*ft_substr(char const *, unsigned int, size_t);
char	**split_string(char *, char *, int *);
char	**split_input(char *, char *, int *);
void	exec_cmd(char **, char **/*, int*/);
void	exec_com(char **, char **, int *);
void	exec_bin_ls(char **, char **, int *);
void	check_exec(List *, char *);
void	ft_bzero(void *, size_t);
void	*ft_memset(void *, int, size_t);
char	**parse(char **, char *, char);
int		isbuiltin(char *);
char	**parse_multiple(char **, char *, char *);
int		isRedirection(char *);
void	imParsingThisShit(char **, char *, List *);
int		ft_check_corresp_word(char *, char *);
int		ft_check_corresp(char *, char *);
void	ft_redi_delimiteur(char **, char *, int , int , List *, char **);
void	ft_re_app(char *, char **, List *);
void	ft_re_in(char **, char **, List *);
void	ft_re_out(char **, char **, List *);
void	check_redirection(char *, List *);
char	*ft_strjoin(char const *, char const *);
int		pipeCreation(int, char **, List *);

#endif
