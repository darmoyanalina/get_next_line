/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:00:09 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/18 20:18:23 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_read(int fd, char *buffer, char *stash)
{
	int		bytes;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		i = 0;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
			return (NULL);
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
		if (ft_strchr(stash, 10, &i))
			break ;
	}
	if (!stash || !stash[0] || !buffer)
		return (NULL);
	return (stash);
}

char	*gnl_helper(char *stash, int fd, char **str, char **buffer)
{
	char	*tmp;
	int		i;

	i = 0;
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer)
		return (NULL);
	tmp = ft_read(fd, *buffer, stash);
	if (!tmp)
	{
		free(*buffer);
		free(stash);
		*buffer = NULL;
		return (NULL);
	}
	ft_strchr(tmp, '\n', &i);
	*str = ft_strdup_n(tmp, i + 1);
	if (!(*str))
	{
		free(stash);
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	char		*tmp;
	static char	*stash;
	int			i;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = stash;
	stash = gnl_helper(stash, fd, &str, &buffer);
	if (!stash && tmp)
		return (NULL);
	i = 0;
	tmp = ft_strdup_n(ft_strchr(stash, '\n', &i), 0);
	free(stash);
	stash = tmp;
	if (buffer)
		free(buffer);
	return (str);
}

// int	main(void)
// {
// 	int fd = open("42_with_nl", O_RDONLY);

// 	char *d = "";
// 	while (d)
// 	{
// 		d = get_next_line(fd);
// 		printf("%s", d);
// 		if (!d)
// 			break ;
// 		free(d);
// 	}
// 	// char c = 0;
// 	// printf("%d\n", strcmp(get_next_line(fd), "0123467890\n"));
// 	// printf("%d\n", strcmp(get_next_line(fd), "1"));
// 	// printf("1read returns: %zd\n", read(fd, &c, 1));
// 	// printf("first = %s", get_next_line(fd));
// 	// int a = open("42_with_nl", O_RDONLY);
// 	// printf("second value = %s", get_next_line(a));
// 	// printf("2read returns: %zd\n", read(fd, &c, 1));
// 	// printf("3read returns: %zd\n", read(fd, &c, 1));
// 	// printf("c = %c\n", c);
// 	// printf("dgggd");
// 	// printf("second = %s", get_next_line(fd));
// 	// printf("second = %s", get_next_line(fd));
// 	// printf("second = %s", get_next_line(fd));
// 	// printf("second = %s", get_next_line(fd));
// 	// printf("third = %s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
