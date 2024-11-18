/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:13 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/18 19:24:33 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args_d	*args_data;
	t_argv		*prog_argv;

	args_data = parse_args(argc, argv, envp);
	if (!args_data)
		return (ft_putstr_fd("./pipex in program program out\n", 3) > 0);
	prog_argv = get_program_argv(argv);
	pipex(args_data, prog_argv);
	free_args_d(args_data);
	free_argv(prog_argv);
}
