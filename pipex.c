/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:38:20 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/24 15:10:17 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	err_handler(int sys_ret, char *err, t_args_d *args, t_argv *argv)
{
	if (sys_ret == -1)
	{
		if (args)
			free_args_d(args);
		if (argv)
			free_argv(argv);
		perror(err);
		exit(EXIT_FAILURE);
	}
}

/* 
pipes:
	pipe[0] --> stdin pipe, program will read from pipe[0][0]
	pipe[1] --> stdout pipe, program will write to pipe[1][1]
*/
static void	forked(int prog_n, t_args_d *prog_d, t_argv *argv_d, int pipx[4])
{
	char	*program_path;
	char	**argv;

	program_path = *((&prog_d->program1) + prog_n);
	argv = argv_d->prog_argv;
	err_handler(access(program_path, X_OK), argv[2 + prog_n], 0, 0);
	argv = *((&argv_d->argv1) + prog_n);
	dup2(pipx[!prog_n], !prog_n);
	dup2(pipx[2 + prog_n], prog_n);
	close(pipx[0]);
	close(pipx[1]);
	execve(program_path, argv, prog_d->envp);
}

static void	forker(int fds[4], pid_t pids[2], int *wstatus)
{
	close(fds[0]);
	close(fds[1]);
	close(fds[2]);
	close(fds[3]);
	*wstatus = 0;
	waitpid(pids[0], NULL, WEXITED);
	waitpid(pids[1], wstatus, WEXITED);
}

/*
Create 2 pipes
Create a pipe that connects the 2 pipes together
Fork 2 times calling forked in each of them

dup to redirect stdin and stdout in fork
execv program in fork

write program 1 with infile from parent
read program 2 from parent and write to outfile

			return_status = write_infile(pipx[0][1], args);
			if (return_status)
				return (return_status);
			return_status = write_outfile(pipx[2][0], args);
			if (return_status)
				return (return_status);
*/
void	pipex(t_args_d *args, t_argv *argv, int *wstatus)
{
	int		pipx[4];
	pid_t	pids[2];

	err_handler(pipe(pipx), "pipe", args, argv);
	err_handler(access(args->infile, R_OK), argv->prog_argv[1], args, argv);
	pipx[2] = open(args->infile, O_RDONLY);
	err_handler(pipx[2], argv->prog_argv[1], args, argv);
	pipx[3] = open(args->outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	err_handler(pipx[3], argv->prog_argv[4], args, argv);
	pids[0] = fork();
	err_handler(pids[0], "fork", args, argv);
	if (pids[0] > 0)
	{
		pids[1] = fork();
		err_handler(pids[1], "fork", args, argv);
		if (pids[1] > 0)
			forker(pipx, pids, wstatus);
		else
			forked(1, args, argv, pipx);
	}
	else
		forked(0, args, argv, pipx);
}
