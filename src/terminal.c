/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:48:14 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 13:06:36 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>

void	enable_raw_mode(t_terminal *terminal)
{
	struct termios	raw;

	raw = terminal->term;
	terminal->raw_mode = 1;
	tcgetattr(STDIN_FILENO, &terminal->term);
	terminal_initialize(terminal);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
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
		cursor_show();
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal->term);
	}
}

void	cursor_hide(void) {
	char	*action;

	action = tgetstr("vi", NULL);
	if (action)
		write(STDIN_FILENO, action, ft_strlen(action));
}

void	cursor_show(void) {
	char	*action;

	action = tgetstr("ve", NULL);
	if (action)
		write(STDIN_FILENO, action, ft_strlen(action));
}
