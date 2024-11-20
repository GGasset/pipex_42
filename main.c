/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:13 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/20 17:21:06 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args_d	*args_data;
	t_argv		*prog_argv;
	char		*usage_str;
	int			return_status;

	usage_str = "Usage: ./pipex infile program1 program2 outfile.\n";
	args_data = parse_args(argc, argv, envp);
	if (!args_data)
		return (ft_putstr_fd(usage_str, 3) > 0);
	prog_argv = get_program_argv(argv);
	return_status = pipex(args_data, prog_argv);
	free_args_d(args_data);
	free_argv(prog_argv);
	if (return_status)
		notify_return_status(return_status);
}
