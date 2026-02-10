/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:41:40 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 21:39:23 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "utils.h"

void	search_clear(t_buffer *buffer)
{
	ft_memset(buffer->value, 0, sizeof(BUFFER_SIZE));
	buffer->length = 0;
}

void	search_add(t_buffer *buffer)
{
	size_t	len;

	len = ft_strlen((const char *)buffer->seq);
	if (buffer->length + len < BUFFER_SIZE)
		ft_memcpy(buffer->value + buffer->length, buffer->seq, len);
	write(STDOUT_FILENO, buffer->seq, ft_strlen((const char *)buffer->seq));
}
