/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:07:30 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/18 20:06:44 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
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

int			main(int argc, char *argv[], char *envp[]);
int			pipex(t_args_d *args, t_argv *argv);
t_args_d	*parse_args(int argc, char *argv[], char *envp[]);
t_bool		free_args_d(t_args_d *args);
t_argv		*get_program_argv(char *argv[]);
t_bool		free_argv(t_argv *argv);

#endif