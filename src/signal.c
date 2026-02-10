/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:33:40 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 12:33:41 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <signal.h>

int	g_signal;

// if (raw_mode) {
// 	char byte = 3;
// 	ioctl(STDIN_FILENO, TIOCSTI, &byte);
// }
static void	sigint_handler(int sig)
{
	g_signal = sig;
}

// terminal_initialize();
// if (raw_mode) cursor_get();
static void	sigwinch_handler(int sig)
{
	g_signal = sig;
}

void	signals_set(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGWINCH, sigwinch_handler);
	signal(SIGQUIT, sigwinch_handler);
	signal(SIGTSTP, sigwinch_handler);
	signal(SIGTERM, sigwinch_handler);
	g_signal = 0;
}
