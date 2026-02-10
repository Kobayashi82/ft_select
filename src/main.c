/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:42:01 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:49:35 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "choices.h"
#include "signals.h"
#include "terminal.h"
#include "input.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_terminal	terminal;
	int			ret;

	ret = choices_load(argc, argv, &terminal.choices);
	if (ret)
		return (ret - 1);
	signal_set();
	enable_raw_mode(&terminal);
	ret = input(&terminal);
	disable_raw_mode(&terminal);
	if (!ret)
		choices_print(terminal.choices);
	choices_free(terminal.choices, 0);
	if (signal_number(-1))
		return (signal_number(-1) + 128);
	return (0);
}
