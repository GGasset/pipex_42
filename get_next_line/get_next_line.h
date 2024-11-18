/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:10:34 by ggasset-          #+#    #+#             */
/*   Updated: 2024/10/09 13:23:26 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <aio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_fd_d
{
	int			fd;
	size_t		cont_len;
	char		*content;
	char		reached_end;
}				t_fd_d;

typedef struct t_fd_arr
{
	t_fd_d	**vs;
	size_t	len;
}			t_fd_arr;

char	*get_next_line(int fd);
t_fd_d	*new_fd(int fd, t_fd_arr *arr);
t_fd_d	*get_fd(t_fd_arr *fds, int search_fd, char add_fd);
size_t	read_fd(t_fd_arr *fds, int fd);
void	*reloc(void *old, size_t len[2], size_t v_sz, size_t strt);

#endif
