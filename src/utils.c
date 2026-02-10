/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:00:19 by vzurera-          #+#    #+#             */
/*   Updated: 2026/02/10 20:51:28 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int		i;
	int		srclen;

	i = 0;
	srclen = 0;
	if (!src)
		return (0);
	while (src[srclen])
		++srclen;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	copy[0] = '\0';
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !s && n)
		return (dst);
	if (!n)
		return (dst);
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			break ;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
