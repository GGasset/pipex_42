/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:25:42 by ggasset-          #+#    #+#             */
/*   Updated: 2024/10/28 11:25:32 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	mem_cp(void *dst, const void *src, ssize_t n)
{
	const char	*src1;
	char		*dst1;
	ssize_t		i;

	src1 = src;
	dst1 = dst;
	i = 0;
	while (i < n && dst && src)
	{
		dst1[i] = src1[i];
		i++;
	}
}

static ssize_t	ft_strchr(const char *s, size_t len, char c)
{
	ssize_t	i;

	i = 0;
	while ((size_t)i < len && s)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// get next line from manager_arr with fd
static char	*try_get_next(t_fd_arr *fds, int fd, char **output)
{
	ssize_t	line_len;
	char	*out;
	t_fd_d	*fd_d;
	size_t	lens[2];

	fd_d = get_fd(fds, fd, 0);
	if (!fd_d)
		return (0);
	if (!fd_d->cont_len)
		return (0);
	line_len = ft_strchr(fd_d->content, fd_d->cont_len, '\n');
	if (line_len == -1 && !fd_d->reached_end)
		return (0);
	line_len += line_len >= 0;
	line_len += (fd_d->cont_len + 1) * (line_len == -1);
	out = malloc(line_len + 1);
	out[line_len] = 0;
	mem_cp(out, fd_d->content, line_len);
	lens[0] = fd_d->cont_len;
	lens[1] = fd_d->cont_len - line_len;
	fd_d->cont_len = lens[1];
	fd_d->content = reloc(fd_d->content, lens, 1, line_len);
	if (out)
		*output = out;
	return (out);
}

// Frees fd whose content has finished
static void	terminate(t_fd_arr *fds)
{
	t_fd_d	*fd_d;
	t_fd_d	**tmp;
	size_t	len;
	size_t	i;

	i = 0;
	while (i < fds->len)
	{
		fd_d = fds->vs[i];
		if (fd_d->reached_end && !fd_d->cont_len)
		{
			free(fd_d);
			tmp = malloc(sizeof(t_fd_d *) * (fds->len - 1));
			mem_cp(tmp, fds->vs, sizeof(t_fd_d *) * i);
			len = sizeof(t_fd_d *) * (fds->len - i - 1);
			mem_cp(tmp + i + 1, fds + i + 1, len);
			free(fds->vs);
			fds->vs = tmp;
			fds->len--;
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_arr	fds;
	char			*out;

	out = 0;
	while (!try_get_next(&fds, fd, &out))
		if (!read_fd(&fds, fd))
			break ;
	terminate(&fds);
	if (!fds.len)
	{
		if (fds.vs)
			free(fds.vs);
		fds.vs = 0;
	}
	return (out);
}

/*int main()
{
	int fd1 = open("./quij.txt", O_RDONLY);
	int fd2 = 0;
	char	*out;
	while ((out = get_next_line(fd1)))
	{
		printf("%s", out);
		free(out);
	}
	close(fd1);
	fd1 = open("./tests.txt", O_RDONLY);
	fd2 = fd1;
	while ((out = get_next_line(fd2)))
	{
		printf("%s", out);
		free(out);
		if (fd2)
			fd2 = 0;
		else
			fd2 = fd1;
	}
	close(fd1);
	return (0);
}*/
