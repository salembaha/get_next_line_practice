/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 07:55:15 by sabahass          #+#    #+#             */
/*   Updated: 2025/09/07 09:09:17 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	res;
	char	*tmp;

	if (!stash)
		stash = ft_substr_gnl("", 0, 0);
	if (!stash)
		return (NULL);
	res = 1;
	while (!ft_strchr_gnl(stash, '\n') && res > 0)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (free(stash), NULL);
		buf[res] = '\0';
		tmp = ft_strjoin_gnl(stash, buf);
		if (!tmp)
			return (free(stash), NULL);
		free(stash);
		stash = tmp;
	}
	if (!*stash)
		return (free(stash), NULL);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr_gnl(stash, 0, i));
}

static char	*stash_after_line(char *stash)
{
	size_t	i;
	char	*next_line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	next_line = ft_substr_gnl(stash, i + 1, ft_strlen_gnl(stash + i + 1));
	free(stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = stash_after_line(stash);
	return (line);
}
