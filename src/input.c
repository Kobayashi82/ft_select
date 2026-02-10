/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:03:49 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:50:11 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "input.h"
#include "utils.h"

static int	process_input(int key, t_terminal *terminal)
{
	t_buffer	*buffer;

	buffer = &terminal->buffer;
	if (key == ENTER || key == ABORT || key == CONTINUE)
		return (key != CONTINUE);
	if ((key >= PAGEUP && key <= PAGEDOWN) || (key >= UP && key <= HOME))
		return (selection_change(key, terminal));
	if (key == SPACE)
		return (selection_mark(terminal));
	if (key == BACKSPACE || key == DELETE)
		return (selection_delete(key, terminal));
	search_add(buffer);
	return (0);
}

static int	read_input(t_buffer *buffer)
{
	ft_memset(&buffer->seq, 0, sizeof(buffer->seq));
	if (read(STDIN_FILENO, buffer->seq, sizeof(buffer->seq) - 1) < 0)
	{
		if (errno == EINTR && signal_number(-1))
			return (ABORT);
		return (CONTINUE);
	}
	if (buffer->seq[0] == '\r' || buffer->seq[0] == '\n')
		return (ENTER);
	if (buffer->seq[0] == ESCAPE)
	{
		if (buffer->seq[1] == '\0')
			return (ABORT);
		if (buffer->seq[1] == '[')
		{
			if (ft_strchr("ABCDFH", buffer->seq[2]))
				return (buffer->seq[2]);
			if (ft_strchr("356", buffer->seq[2]) && buffer->seq[3] == '~')
				return (buffer->seq[2]);
		}
		return (CONTINUE);
	}
	return (buffer->seq[0]);
}

int	input(t_terminal *terminal)
{
	int	key;

	key = ABORT;
	terminal->buffer.length = 0;
	terminal->buffer.value = (char *)malloc(BUFFER_SIZE * sizeof(char));
	ft_memset(terminal->buffer.value, 0, BUFFER_SIZE);
	while (1)
	{
		key = read_input(&terminal->buffer);
		if (process_input(key, terminal))
			break ;
	}
	if (terminal->buffer.value)
		free(terminal->buffer.value);
	return (key == ABORT);
}
