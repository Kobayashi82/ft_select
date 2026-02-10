/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:15:18 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:50:52 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "choices.h"
#include <stddef.h>
#include <termios.h>

#define CURSOR_SHOW		"ve"
#define CURSOR_HIDE		"vi"
#define ALTERNATE_ON	"ti"
#define ALTERNATE_OFF	"te"
#define CLEAR			"cl"

#define BUFFER_SIZE		1024

typedef struct s_buffer
{
	unsigned char	seq[8];
	char			*value;
	size_t			length;
}	t_buffer;

typedef struct s_terminal
{
	struct termios	term;
	size_t			rows;
	size_t			cols;
	int				raw_mode;
	t_buffer		buffer;
	t_choices		*choices;
}	t_terminal;

void	terminal_do_action(const char *action);
void	terminal_update_limits(t_terminal *terminal);
int		terminal_initialize(t_terminal *terminal);
void	enable_raw_mode(t_terminal *terminal);
void	disable_raw_mode(t_terminal *terminal);
