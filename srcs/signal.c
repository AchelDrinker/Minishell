/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:35:55 by humartin          #+#    #+#             */
/*   Updated: 2022/10/07 15:44:31 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void handle_shell(int signum)
{
 if (signum == SIGINT)
 {
  ft_putstr_fd("\n", 1);
  rl_on_new_line();
  rl_replace_line("", 0);
  rl_redisplay();
 }
 else
  return ;
}

void handle_exec(int signum)
{
 if (signum == SIGINT)
  printf("\n");
 else
  return ;
}

void signal_exec(void)
{
 signal(SIGQUIT, handle_exec);
 signal(SIGINT, handle_exec);
}
/*---- trap for signal ----*/
void signal_trap(void)
{
 signal(SIGQUIT, SIG_IGN);
 signal(SIGINT, handle_shell);
}
