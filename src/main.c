/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:20:32 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 15:07:07 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <termcap.h>

static void	*choices_free(t_choices *choices, int is_error)
{
	while (choices)
	{
		t_choices *tmp = choices->next;
		free(choices->value);
		free(choices);
		choices = tmp;
	}
	if (is_error)
		write(STDERR_FILENO, "Memory allocation failed\n", 25);
	return (NULL);
}

static void	choices_add(t_choices **choices, t_choices *new_choice)
{
	if (!*choices)
		*choices = new_choice;
	else
	{
		t_choices *tmp = *choices;
		while (tmp->next)
			tmp = tmp->next;
		new_choice->prev = tmp;
		tmp->next = new_choice;
	}
}

static t_choices	*choices_load(int argc, char **argv)
{
	t_choices	*choices;
	int			i;

	choices = NULL;
	i = 1;
	while (i < argc)
	{
		t_choices	*new_choice;
		new_choice = (t_choices *)malloc(sizeof(t_choices));
		if (!new_choice)
			return (choices_free(choices, 1));
		choices_add(&choices, new_choice);
		new_choice->value = ft_strdup(argv[i]);
		if (!new_choice->value)
			return (choices_free(choices, 1));
		new_choice->selected = 0;
		new_choice->prev = NULL;
		new_choice->next = NULL;
		i++;
	}

	return (choices);
}

static void	choices_print(t_choices *choices)
{
	while (choices)
	{
		write(STDOUT_FILENO, choices->value, ft_strlen(choices->value));
		write(STDOUT_FILENO, "\n", 1);
		choices = choices->next;
	}
}

int	main(int argc, char **argv)
{
	t_terminal	terminal;
	t_choices	*choices;
	t_buffer	buffer;

	if (argc < 2)
		return (0);
	choices = choices_load(argc, argv);
	if (!choices)
		return (1);
	signal_set();
	enable_raw_mode(&terminal);
	choices_print(choices);

	buffer.size = 1024;
	buffer.position = 0;
	buffer.length = 0;
	buffer.value = (char *)malloc(buffer.size * sizeof(char));
	ft_memset(buffer.value, 0, buffer.size);

	while (1)
	{
		int readed = read(STDIN_FILENO, &buffer.c, 1);
		if (readed < 0) {
			if (errno == EINTR) {
				int sig = signal_number(-1);
				if (sig)
					break;
			}
			continue;
		}
	}
	if (buffer.value) free(buffer.value);
	disable_raw_mode(&terminal);
	choices_free(choices, 0);
	return (0);
}
