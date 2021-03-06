/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:19:53 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 18:53:40 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_next_line(char *prev, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		nbytes;

	nbytes = BUFFER_SIZE;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!prev)
		prev = ft_calloc(1);
	while (nl_pos(prev) == -1 && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(prev);
			return (NULL);
		}
		prev = append(prev, buffer, nbytes);
	}
	if (!ft_strlen(prev))
	{
		free(prev);
		return (NULL);
	}
	return (prev);
}

char	*get_result(char *prev)
{
	char	*line;
	int		pos;

	if (!prev)
		return (prev);
	pos = nl_pos(prev);
	if (pos == -1)
	{
		line = copy(prev, ft_strlen(prev));
		return (line);
	}
	else
	{
		line = copy(prev, pos + 1);
		return (line);
	}
	return (NULL);
}

char	*actualiza_prev(char *prev)
{
	char	*new_prev;
	int		pos;

	pos = nl_pos(prev);
	if (pos == -1 || pos == ft_strlen(prev))
	{
		free(prev);
		return (NULL);
	}
	else
	{
		new_prev = copy(prev + pos + 1, ft_strlen(prev) - pos - 1);
		free(prev);
		return (new_prev);
	}
}

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*line;

	prev = read_next_line(prev, fd);
	if (!prev)
		return (NULL);
	line = get_result(prev);
	prev = actualiza_prev(prev);
	return (line);
}
