/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:11:11 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 18:53:02 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t bytes);
int		ft_strlen(char *str);
int		nl_pos(char *str);
char	*append(char *prev, char *buffer, int nbytes);
char	*copy(char *prev, int nchar);
char	*read_next_line(char *prev, int fd);
char	*get_result(char *prev);
char	*actualiza_prev(char *prev);
char	*get_next_line(int fd);
#endif
