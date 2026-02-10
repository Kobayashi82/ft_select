/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:35:46 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 15:12:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	terminal_do_action(const char *action)
{
	char	*value;

	value = tgetstr(action, NULL);
	if (value)
		write(STDOUT_FILENO, value, ft_strlen(value));
}

void	terminal_update_limits(t_terminal *terminal)
{
	terminal->rows = tgetnum("li");
	terminal->cols = tgetnum("co");
}

int	terminal_initialize(t_terminal *terminal)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (!termtype)
	{
		write(STDERR_FILENO, "Could not access the termcap data base.\n", 41);
		return (1);
	}
	success = tgetent(NULL, termtype);
	if (success < 0)
	{
		write(STDERR_FILENO, "Could not access the termcap data base.\n", 41);
		return (1);
	}
	if (success == 0)
	{
		write(STDERR_FILENO, "Terminal type is not defined.\n", 31);
		return (1);
	}
	terminal_update_limits(terminal);
	return (0);
}
