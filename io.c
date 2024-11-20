/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germangasset <germangasset@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:03:06 by germangasse       #+#    #+#             */
/*   Updated: 2024/11/20 16:53:56 by germangasse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	write_infile(int write_fd, t_args_d *args)
{
	int		infile_fd;
	char	*infile;
	char	buff[1];

	infile_fd = open(args->infile, O_RDONLY);
	if (infile_fd == -1)
		return (1);
	infile = 0;
	while (read(infile_fd, buff, 1) > 0)
		infile = ft_strjoin_free(infile, buff, 1, 0);
	close(infile_fd);
	if (write(write_fd, infile, ft_strlen(infile)) == -1)
		return (2);
	return (0);
}

int	write_outfile(int read_fd, t_args_d *args)
{
	int		outfile_fd;
	char	*outfile;
	char	buff[1];
	
	while (read(read_fd, buff, 1) > 0)
		outfile = ft_strjoin_free(outfile, buff, 1, 0);
	outfile_fd = open(args->outfile, O_WRONLY | O_CREAT);
	if (outfile_fd == -1)
		return (3);
	if (write(outfile_fd, outfile, ft_strlen(outfile)) == -1)
	{
		close(outfile_fd);
		return (4);
	}
	close(outfile_fd);
	return (0);
}
