/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:10:54 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:38:58 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "choices.h"
#include "utils.h"

static void	choices_add(t_choices **choices, t_choices *new_choice)
{
	t_choices	*tmp;

	if (!*choices)
		*choices = new_choice;
	else
	{
		tmp = *choices;
		while (tmp->next)
			tmp = tmp->next;
		new_choice->prev = tmp;
		tmp->next = new_choice;
	}
}

int	choices_load(int argc, char **argv, t_choices **choices)
{
	t_choices	*new_choice;
	int			i;

	if (argc < 2)
		return (1);
	*choices = NULL;
	i = 1;
	while (i < argc)
	{
		new_choice = (t_choices *)malloc(sizeof(t_choices));
		if (!new_choice)
			return (choices_free(*choices, 1), 2);
		choices_add(choices, new_choice);
		new_choice->value = ft_strdup(argv[i]);
		if (!new_choice->value)
			return (choices_free(*choices, 1), 2);
		new_choice->selected = 0;
		new_choice->marked = 1;
		new_choice->prev = NULL;
		new_choice->next = NULL;
		i++;
	}
	return (0);
}

void	choices_free(t_choices *choices, int is_error)
{
	t_choices	*tmp;

	while (choices)
	{
		tmp = choices->next;
		free(choices->value);
		free(choices);
		choices = tmp;
	}
	if (is_error)
		write(STDERR_FILENO, "Memory allocation failed\n", 25);
}

void	choices_print(t_choices *choices)
{
	int	written;

	if (signal_number(-1))
		return ;
	written = 0;
	while (choices)
	{
		if (choices->marked)
		{
			if (written)
				write(STDOUT_FILENO, " ", 1);
			written = 1;
			write(STDOUT_FILENO, choices->value, ft_strlen(choices->value));
		}
		choices = choices->next;
	}
	if (written)
		write(STDOUT_FILENO, "\n", 1);
}
