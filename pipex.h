/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:07:30 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/11 13:35:18 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
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
void		pipex(t_args_d *args, t_argv *argv);
int			write_infile(int write_fd, t_args_d *args);
int			write_outfile(int read_fd, t_args_d *args);
t_args_d	*parse_args(int argc, char *argv[], char *envp[]);
int			file_exists(char *file_path);
char		*get_from_path(char *filename, char *envp[]);
char		*get_envp(char *key, char *envp[]);
char		*replace_start(char *s, char *old, char *new, char free_s);
t_argv		*get_program_argv(char *argv[]);
void		*free_args_d(t_args_d *args);
void		*free_argv(t_argv *argv);
int			notify_return_status(size_t status);
void		substr_free(char **s, unsigned int start, unsigned int len);

#endif