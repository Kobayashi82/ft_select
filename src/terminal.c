/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:48:14 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 17:44:26 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include <unistd.h>
#include <fcntl.h>

void	enable_raw_mode(t_terminal *terminal)
{
	struct termios	raw;
	int				tty_fd;

	terminal->raw_mode = 1;
	tty_fd = open("/dev/tty", O_RDWR);
	if (tty_fd < 0)
		tty_fd = STDIN_FILENO;
	tcgetattr(tty_fd, &terminal->term);
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
	tcsetattr(tty_fd, TCSAFLUSH, &raw);
	if (tty_fd != STDIN_FILENO)
		close(tty_fd);
}

void	disable_raw_mode(t_terminal *terminal)
{
	int	tty_fd;

	if (terminal->raw_mode)
	{
		terminal->raw_mode = 0;
		terminal_do_action(ALTERNATE_OFF);
		terminal_do_action(CURSOR_SHOW);
		tty_fd = open("/dev/tty", O_RDWR);
		if (tty_fd >= 0)
		{
			tcsetattr(tty_fd, TCSAFLUSH, &terminal->term);
			close(tty_fd);
		}
		else
			tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal->term);
	}
}
