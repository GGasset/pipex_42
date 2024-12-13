/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:13 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/29 18:25:34 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	notify_return_status(size_t status)
{
	char		*tmp_str;

	tmp_str = "Usage: ./pipex infile program1 program2 outfile.\n";
	if (status < 5)
		ft_putstr_fd(tmp_str, 2);
	if (!(status - 1))
		return ((size_t)ft_putstr_fd("infile error\n", 2));
	if (!(status - 2))
		return ((size_t)ft_putstr_fd("program1 error\n", 2));
	if (!(status - 3))
		return ((size_t)ft_putstr_fd("program2 error\n", 2));
	if (!(status - 4))
		return ((size_t)ft_putstr_fd("outfile error\n", 2));
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_args_d	*args_data;
	t_argv		*prog_argv;

	args_data = parse_args(argc, argv, envp);
	if ((size_t)args_data < 5)
	{
		return (notify_return_status((size_t)args_data));
	}
	prog_argv = get_program_argv(argv);
	if (!prog_argv)
	{
		ft_putstr_fd("Error during malloc.", 1);
		free_args_d(args_data);
		return (0);
	}
	pipex(args_data, prog_argv);
	free_args_d(args_data);
	free_argv(prog_argv);
}
