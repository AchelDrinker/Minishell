/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:09:59 by humartin          #+#    #+#             */
/*   Updated: 2022/11/07 16:46:44 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define GREEN			"\x1b[32m"
# define RESET			"\x1b[0m"
# define RED			"\033[91m"

# define F_OK	0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <fcntl.h>

int	g_status;

typedef struct s_tube
{
	pid_t	pid;
}t_tube;

typedef struct Cell_t
{
	char			*data;
	struct Cell_t	*next;
}t_List,	t_Cell;

t_List	*emptylist(void);
t_List	*copyenv(t_List *L, char **env);
int		isemptylist(t_List *L);
long	lenlist(t_List *L);
t_List	*addat(t_List *L, char *data, int pos);
char	*getat(t_List *L, int pos);
void	setat(t_List *L, char *data, int pos);
t_List	*freeat(t_List *L, int pos);
t_List	*freelist(t_List *L);
void	printlist(t_List *L);
void	printcell(t_List *L, int pos, int depart);
void	printcell_n(t_List *L, int pos, int depart);
size_t	ft_strlen(const char *str);
char	*ft_strncat(t_List *dest, t_List *src, int nb);
char	*ft_strnstr(t_List *big, const char *little, size_t len);
void	ft_putchar_fd(char c, int fd);
int		echo_env_n(char *line, int i, t_List *environ, int ii);
int		echo_env(char *line, int i, t_List *environ, int ii);
void	ft_echo(char *line, int i, t_List *environ);
void	ft_echo_n(char *line, int i, t_List *environ);
t_List	*check_echo(char *line, char *str, char *str2, t_List *environ);
int		check_pwd(char *line, char *str, t_List *environ);
int		check_env(char *line, char *str, t_List *environ);
t_List	*check_input(char *line, t_List *environ);
t_List	*check_export(char *line, char *str, t_List *environ);
t_List	*ft_unsetenv(t_List *environ, char *line);
t_List	*check_unset(char *line, char *str, t_List *environ);
int		check_path(t_List *environ);
void	ft_error_path(char *line);
void	ft_putstr_fd(char *str, int fd);
void	ft_error_echo(char *line);
void	signal_trap(void);
void	signal_exec(void);
void	handle_exec(int signum);
void	handle_shell(int signum);
void	check_exit(char *line, char *s1);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_quotes(char *line, int i);
int		ft_checker_exit(char *line);
void	ft_error_char(char *str, int i);
void	check_spe_char(char *line);
int		ft_single_quotes(char *line, char *s1);
void	header(void);
t_List	*check_cd(char *line, char *str, t_List *environ, int i);
char	*ft_strcpylen(char *buff, char *str);
int		ft_strncmp(const char *first, const char *second, size_t lenght);
char	*ft_strrchr(const char *str, int x);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *s1, const char *s2);
int		find_env_pos(t_List *environ, char *str);
void	check_status(char *line, char *line2);
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);
int		ft_splitlen(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	exec_cmd(char **split, char **split_line);
void	check_exec(t_List *environ, char *line);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *pointer, int value, size_t count);
char	**parse(char **L, char *line, char c);
int		isbuiltin(char *line);
int		isredirection(char *line);
void	im_parsing_this_shit(char **parsed_shit,
			char *line, t_List *environ, int i);
int		ft_check_corresp_word(char *s1, char *s2);
int		ft_check_corresp(char *s1, char *s2);
void	ft_redi_delimiteur(char **arg, char *word, t_List *environ, char **fd);
void	ft_re_app(char *arg, char **fich, t_List *environ);
void	ft_re_in(char **arg, char **fich, t_List *environ);
void	ft_re_out(char **arg, char **fich, t_List *environ);
void	check_redirection(char *line, t_List *environ);
char	*ft_strjoin(char const *s1, char const *s2);
int		pipecreation(int countfork, char **parsed_input, t_List *environ);
int		pipecreation2(char **parsed_input, t_List *environ);
void	exec_com(char **sp, char **sl, int i, int j);
void	built_in_cd(char *path, t_List *environ, char *oldpwd);
int		check_iii(char *line, int i, int iii);
int		do_count(char *line, int i, int count, int iii);
char	**ft_split_exe(char const *s, char c);
void	exec_bin_ls(char **sp, char **sl, int i, int j);
int		county(int y, const char *s);
char	**returnstr(char const *s, char c, char **str);
t_List	*prompt(char *line, char **parsed_input, t_List *environ, int i);
int		countfork(char *line);
void	parsing_this1(char **parsed_shit,
			char *line, t_List *environ);
void	parsing_this2(char **parsed_shit,
			char *line, t_List *environ);
void	parsing_this3(char **parsed_shit,
			char *line, t_List *environ);
void	parsing_this4(char **parsed_shit,
			char *line, t_List *environ);

#endif
