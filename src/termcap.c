/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:35:46 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 13:12:44 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdlib.h>
#include <termcap.h>

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
