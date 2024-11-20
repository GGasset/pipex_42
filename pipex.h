/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germangasset <germangasset@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:07:30 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/20 16:58:41 by germangasse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef char	t_bool;

typedef struct s_args_d
{
	char	*infile;
	char	*program1;
	char	*program2;
	char	*outfile;
	char	**envp;
}	t_args_d;

typedef struct s_argv
{
	char	**argv1;
	char	**argv2;
}	t_argv;

/*
	TODO:
		Close pipex file descriptors
*/
int			main(int argc, char *argv[], char *envp[]);
int			pipex(t_args_d *args, t_argv *argv);
int			write_infile(int write_fd, t_args_d *args);
int			write_outfile(int read_fd, t_args_d *args);
t_args_d	*parse_args(int argc, char *argv[], char *envp[]); // TODO
t_argv		*get_program_argv(char *argv[]); // TODO
t_bool		free_args_d(t_args_d *args); //TODO
t_bool		free_argv(t_argv *argv); // TODO
void		notify_return_status(int status); // TODO

#endif