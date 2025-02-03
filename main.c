/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:13 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/24 21:06:15 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_null(t_args_d *args_d)
{
	int	is_null;

	is_null = 0;
	is_null = is_null || !args_d->infile || !args_d->outfile;
	is_null = is_null || !args_d->program1 || !args_d->program2;
	return (is_null);
}

int	notify_return_status(t_args_d *args_d, char **argv)
{
	int	status;

	if (!args_d->infile)
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (!args_d->program1 && args_d->program2)
	{
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (!args_d->program2)
	{
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (!args_d->outfile && args_d->infile)
	{
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	status = 127 * (args_d->infile != 0);
	free_args_d(args_d);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int			wstatus;
	t_args_d	*args_data;
	t_argv		*prog_argv;

	if (argc != 5)
	{
		ft_putstr_fd("Invalid param count.", 2);
		return (0);
	}
	if (!envp)
		return (ft_putstr_fd("Null envp\n", 2));
	args_data = parse_args(argc, argv, envp);
	if (check_null(args_data))
		return (notify_return_status(args_data, argv));
	prog_argv = get_program_argv(argv);
	if (!prog_argv)
	{
		ft_putstr_fd("Error during malloc.", 1);
		free_args_d(args_data);
		return (0);
	}
	pipex(args_data, prog_argv, &wstatus);
	free_args_d(args_data);
	free_argv(prog_argv);
	return (WEXITSTATUS(wstatus));
}
