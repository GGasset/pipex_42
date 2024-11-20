/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germangasset <germangasset@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:38:20 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/20 16:57:24 by germangasse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
pipes:
	pipe[0] --> stdin pipe, program will read from pipe[0][0]
	pipe[1] --> stdout pipe, program will write to pipe[1][1]
*/
static void	forked(int prog_n, t_args_d *prog_d, t_argv *argv_d, int pipx[3][2])
{
	char	*program_path;
	char	**argv;

	program_path = prog_d->program1 + prog_n;
	argv = argv_d->argv1 + prog_n;
	dup2(pipx[prog_n][0], 0);
	dup2(pipx[prog_n + 1][1], 1);
	execve(program_path, argv, prog_d->envp);
}

static void	create_pipes(int pipes[3][2])
{
	pipe(pipes[0]);
	pipe(pipes[1]);
	pipe(pipes[2]);
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
	int		pipx[3][2];
	pid_t	pids[2];
	int		return_status;

	create_pipes(pipx);
	pids[0] = fork();
	if (pids[0] > 0)
	{
		pids[1] = fork();
		if (pids[1] > 0)
		{
			return_status = write_infile(pipx[0][1], args);
			if (return_status)
				return (return_status);
			waitpid(pids[0], 0, 0);
			waitpid(pids[1], 0, 0);
			return_status = write_outfile(pipx[2][0], args);
			if (return_status)
				return (return_status);
		}
		else
			forked(1, args, argv, pipx);
	}
	else
		forked(0, args, argv, pipx);
}
