/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:13:26 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:49:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "choices.h"
#include "terminal.h"

#define ABORT		-2
#define TERMINATE	-1
#define CONTINUE	0
#define ENTER		10
#define ESCAPE		27
#define SPACE		32
#define DELETE		51
#define PAGEUP		53
#define PAGEDOWN	54
#define UP			65
#define DOWN		66
#define RIGHT		67
#define LEFT		68
#define END			70
#define HOME		72
#define BACKSPACE	127

void	search_clear(t_buffer *buffer);
void	search_add(t_buffer *buffer);
int		selection_change(int key, t_terminal *terminal);
int		selection_mark(t_terminal *terminal);
int		selection_delete(int key, t_terminal *terminal);
int		input(t_terminal *terminal);
