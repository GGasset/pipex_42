/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:38:20 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/18 20:33:48 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	forked(int prog_n, t_args_d *prog_d, t_argv *argv_d, int pipe[2])
{
	char	*program_path;
	char	**argv;

	program_path = prog_d->program1 + prog_n;
	argv = argv_d->argv1 + prog_n;
	dup2(pipe[0], 0);
	dup2(pipe[1], 1);
	execve(program_path, argv, prog_d->envp);
}

/*
Create 2 pipes
Create a pipe that connects the 2 pipes together
Fork 2 times calling forked in each of them

dup to redirect stdin and stdout in fork
execv program in fork

write program 1 with infile from parent
read program 2 from parent and write to outfile
*/
int	pipex(t_args_d *args, t_argv *argv)
{
	int		pipes[2][3];

	pipe(pipes[0]);
	pipe(pipes[1]);
	pipe(pipes[2]);
	if (fork() > 0)
		//write()
		if (fork() > 0)
		{
			
		}
		else
			forked(1, args, argv, pipes[2]);
	else
		forked(0, args, argv, pipes[0]);
}
