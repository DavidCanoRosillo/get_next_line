/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:50:19 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 18:52:03 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t bytes)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(bytes);
	while (i < bytes)
		res[i++] = 0;
	return ((void *) res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nl_pos(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*append(char *prev, char *buffer, int nbytes)
{
	char	*new_prev;
	int		i;
	int		j;

	new_prev = ft_calloc(ft_strlen(prev) + nbytes + 1);
	i = 0;
	j = 0;
	while (prev[i])
	{
		new_prev[i] = prev[i];
		i++;
	}
	while (j < nbytes)
	{
		new_prev[i + j] = buffer[j];
		j++;
	}
	free(prev);
	return (new_prev);
}

char	*copy(char *prev, int nchar)
{
	int		i;
	char	*res;

	res = ft_calloc(ft_strlen(prev) + 1);
	i = 0;
	while (i < nchar)
	{
		res[i] = prev[i];
		i++;
	}
	return (res);
}
