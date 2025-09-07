/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 07:55:28 by sabahass          #+#    #+#             */
/*   Updated: 2025/09/07 09:14:39 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len_1 = ft_strlen_gnl(s1);
	len_2 = ft_strlen_gnl(s2);
	res = (char *)malloc(len_1 + len_2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len_1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_2)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	slen = ft_strlen_gnl(s);
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
