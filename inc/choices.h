/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:12:59 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 17:02:33 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_choices
{
	char				*value;
	int					selected;
	int					marked;
	struct s_choices	*prev;
	struct s_choices	*next;
}	t_choices;

int		choices_load(int argc, char **argv, t_choices **choices);
void	choices_free(t_choices *choices, int is_error);
void	choices_print(t_choices *choices);
