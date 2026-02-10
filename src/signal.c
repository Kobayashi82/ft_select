/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:33:40 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 15:00:50 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

// if (raw_mode) {
// 	char byte = 3;
// 	ioctl(STDIN_FILENO, TIOCSTI, &byte);
// }
static void	sigint_handler(int sig)
{
	signal_number(sig);
}

// terminal_initialize();
// if (raw_mode) cursor_get();
static void	sigwinch_handler(int sig)
{
	signal_number(sig);
}

void	signal_set(void)
{
	struct sigaction	sa;

	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sa.sa_handler = sigwinch_handler;
	sigaction(SIGWINCH, &sa, NULL);
}

int	signal_number(int n)
{
	static int	sig_n;

	if (n < 0)
		return (sig_n);
	sig_n = n;
	return (sig_n);
}
