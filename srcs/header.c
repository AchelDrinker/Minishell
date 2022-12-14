/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:54:29 by humartin          #+#    #+#             */
/*   Updated: 2022/11/02 15:36:35 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	header(void)
{
	printf(GREEN" ___ _    _____  _____ _  _ ___ _    _   \n");
	printf(GREEN"| __| |  | __( (/ / __| || | __| |  | |   \n");
	printf(GREEN"| _|| |__| _| >  <(__ ( __ | _|| |__| |__\n");
	printf(GREEN"|_| |____|___/_/(_(___/_||_|___|____|____|\n");
	printf(GREEN"===================X======================\n");
	printf(RESET"Minishell Kev&Hugo 1.0"GREEN"||||||||||||||||||||\n");
	printf(GREEN"===================X======================\n"RESET);
}
