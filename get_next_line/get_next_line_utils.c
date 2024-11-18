/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:19:19 by ggasset-          #+#    #+#             */
/*   Updated: 2024/10/28 11:24:23 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_d	*new_fd(int fd, t_fd_arr *arr)
{
	t_fd_d	*out;
	size_t	lens[2];

	out = malloc(sizeof(t_fd_d));
	if (!out)
		return (0);
	out->fd = fd;
	out->cont_len = 0;
	out->content = 0;
	out->reached_end = 0;
	if (arr)
	{
		lens[0] = arr->len;
		lens[1] = arr->len + 1;
		arr->vs = reloc(arr->vs, lens, sizeof(t_fd_d **), 0);
		arr->len++;
		arr->vs[arr->len - 1] = out;
	}
	return (out);
}

// Creates and adds fd if it doesn't exists and add_fd evaluates true
t_fd_d	*get_fd(t_fd_arr *fds, int search_fd, char add_fd)
{
	t_fd_d	*out;
	size_t	i;

	i = 0;
	while (i < fds->len)
	{
		if (fds->vs[i]->fd == search_fd)
			return (fds->vs[i]);
		i++;
	}
	if (!add_fd)
		return (0);
	out = new_fd(search_fd, fds);
	return (out);
}

// add content to fd
size_t	read_fd(t_fd_arr *fds, int fd)
{
	t_fd_d	*fd_d;
	char	*buffer;
	ssize_t	bytes_r;
	size_t	lens[2];
	size_t	i;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	bytes_r = read(fd, buffer, BUFFER_SIZE);
	fd_d = get_fd(fds, fd, bytes_r > 0);
	if (fd_d && bytes_r < BUFFER_SIZE)
		fd_d->reached_end = 1;
	free((void *)((size_t)buffer * (bytes_r <= 0 || !fd_d)));
	if (bytes_r <= 0 || !fd_d)
		return (0);
	lens[0] = fd_d->cont_len;
	lens[1] = lens[0] + bytes_r;
	fd_d->content = reloc(fd_d->content, lens, 1, 0);
	fd_d->cont_len += bytes_r;
	i = 0;
	while (i++ < (size_t)bytes_r && fd_d->content)
		fd_d->content[lens[0] + i - 1] = buffer[i - 1];
	free(buffer);
	return ((size_t)bytes_r);
}

void	*reloc(void *old, size_t len[2], size_t v_size, size_t strt)
{
	char	*new;
	size_t	i;

	if (!len[1])
	{
		if (old)
			free(old);
		return (0);
	}
	new = malloc(len[1] * v_size);
	i = 0;
	while (i < len[1] * v_size && new)
	{
		new[i] = 0;
		if (i + strt < len[0] * v_size && old)
			new[i] = ((char *)old)[i + strt];
		i++;
	}
	if (old)
		free(old);
	return (new);
}
