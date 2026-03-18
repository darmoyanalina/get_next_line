/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:00:13 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/18 20:18:02 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c, int *i)
{
	unsigned char	l;

	l = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[(*i)])
	{
		if (s[*i] == l)
			return ((char *)&s[(*i + 1)]);
		(*i)++;
	}
	if (c == '\0')
		return ((char *)&s[*i]);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s;

	i = ft_strlen(dst);
	j = 0;
	s = i;
	if (!size || size <= i)
		return (size + ft_strlen(src));
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (s + ft_strlen(src));
}

char	*ft_strdup_n(const char *s, size_t n)
{
	char	*p;
	char	*tmp;
	size_t	i;

	if (!s)
		return (NULL);
	if (n == 0)
		n = ft_strlen(s) + 1;
	p = malloc(n + 1);
	if (!p)
		return (NULL);
	tmp = p;
	i = 0;
	while (s[i] && i < n)
		*(tmp++) = s[i++];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	ss1;
	size_t	ss2;

	if (!s2)
		return (NULL);
	ss1 = 0;
	if (s1)
		ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	s = malloc(ss1 + ss2 + 1);
	if (!s)
		return (NULL);
	if (!s1)
	{
		free(s);
		s = ft_strdup_n(s2, ss2);
		return (s);
	}
	s[0] = '\0';
	ft_strlcat(s, s1, ss1 + 1);
	ft_strlcat(s, s2, ss1 + ss2 + 1);
	return (s);
}
