/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:51:00 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:53:49 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "utils.h"

int	display_update(t_terminal *terminal)
{
	(void) terminal;
	return (0);
}

t_choices	*selected_choice(t_choices *choices)
{
	while (choices)
	{
		if (choices->selected)
			return (choices);
		choices = choices->next;
	}
	return (NULL);
}

int	selection_change(int key, t_terminal *terminal)
{
	t_buffer	*buffer;

	buffer = &terminal->buffer;
	search_clear(buffer);
	(void) key;
	write(STDOUT_FILENO, "Right ", 6);
	return (0);
}

int	selection_mark(t_terminal *terminal)
{
	t_buffer	*buffer;
	t_choices	*choice;

	buffer = &terminal->buffer;
	search_clear(buffer);
	write(STDOUT_FILENO, "Space ", 6);
	choice = selected_choice(terminal->choices);
	if (!choice)
		return (0);
	choice->marked = !choice->marked;
	return (display_update(terminal));
}

int	selection_delete(int key, t_terminal *terminal)
{
	t_buffer	*buffer;
	t_choices	*choice;

	(void) key;
	buffer = &terminal->buffer;
	search_clear(buffer);
	write(STDOUT_FILENO, "Delete ", 7);
	choice = selected_choice(terminal->choices);
	if (!choice)
		return (0);
	choice->marked = !choice->marked;
	return (display_update(terminal));
}
