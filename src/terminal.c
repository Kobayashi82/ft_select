/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:48:14 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 15:12:39 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	enable_raw_mode(t_terminal *terminal)
{
	struct termios	raw;

	terminal->raw_mode = 1;
	tcgetattr(STDIN_FILENO, &terminal->term);
	raw = terminal->term;
	terminal_initialize(terminal);
	terminal_do_action(CURSOR_HIDE);
	terminal_do_action(ALTERNATE_ON);
	terminal_do_action(CLEAR);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void	disable_raw_mode(t_terminal *terminal)
{
	if (terminal->raw_mode)
	{
		terminal->raw_mode = 0;
		terminal_do_action(ALTERNATE_OFF);
		terminal_do_action(CURSOR_SHOW);
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal->term);
	}
}
