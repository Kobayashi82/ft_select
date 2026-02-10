/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:20:38 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 13:12:46 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.h"
#include <unistd.h>
#include <termios.h>

#define NC   	"\033[0m"		 	// Default

#define RD		"\033[0;31m"	 	// Red
#define G     	"\033[0;32m"	 	// Green
#define Y     	"\033[0;33m"	 	// Yellow
#define B     	"\033[0;34m"	 	// Blue
#define M     	"\033[0;35m"	 	// Magenta
#define C     	"\033[0;36m"	 	// Cyan
#define W     	"\033[0;37m"	 	// White
#define BR 		"\033[38;5;130m" 	// Light Brown

#define BRD		"\033[1;31m"	 	// Bold Red
#define BG     	"\033[1;32m"	 	// Bold Green
#define BY     	"\033[1;33m"	 	// Bold Yellow
#define BB     	"\033[1;34m"	 	// Bold Blue
#define BM     	"\033[1;35m"	 	// Bold Magenta
#define BCY     "\033[1;36m"	 	// Bold Cyan
#define BW     	"\033[1;37m"	 	// Bold White

#define BD		"\033[1m"			// Bold
#define UN 		"\033[4m"		 	// Underline
#define IT 		"\033[3m"		 	// Italic

typedef struct s_buffer
{
	unsigned char	c;
	char			*value;
	size_t			size;
	size_t			position;
	size_t			length;
}	t_buffer;

typedef struct s_terminal
{
	struct termios	term;
	size_t			rows;
	size_t			cols;
	int				raw_mode;
	t_buffer		buffer;
}	t_terminal;

extern int	g_signal;

void		signals_set(void);
void		enable_raw_mode(t_terminal *terminal);
void		disable_raw_mode(t_terminal *terminal);
void		terminal_update_limits(t_terminal *terminal);
int			terminal_initialize(t_terminal *terminal);
size_t		char_size(unsigned char c);
size_t		char_width(size_t position, const char *value);
size_t		chars_width(size_t from, size_t to, const char *value);
size_t		char_prev(size_t position, const char *value);
size_t		nocolor_length(const char *str);
char		*remove_colors(const char *str);
void		cursor_up(void);
void		cursor_down(void);
void		cursor_left(int moves);
void		cursor_right(int moves);
void		cursor_get(void);
void		cursor_set(size_t new_row, size_t new_col);
void		cursor_move(size_t from, size_t to);
void		cursor_update(size_t length);
void		cursor_start_column(void);
void		cursor_hide(void);
void		cursor_show(void);
int			write_value(int fd, const char *value, size_t length);
