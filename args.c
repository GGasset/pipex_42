/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:04:22 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/18 19:12:52 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char *path, char *envp[])
{
	
}

t_args_d	*parse_args(int argc, char *argv[], char *envp[])
{
	t_args_d	*output;
	
	if (argc != 5)
		return (0);
	output = malloc(sizeof(t_args_d));
	if (!output)
		return (0);
	ft_bzero((void *)&output, sizeof(t_args_d));
	output->infile = get_path(argv[1], envp);
	if (!output->infile)
		return (free_args_d(output));
	output->program1 = get_path(argv[2], envp);
	if (!output->program1)
		return (free_args_d(output));
	output->program2 = get_path(argv[3], envp);
	if (!output->program2)
		return (free_args_d(output));
	output->outfile = get_path(argv[4], envp);
	if (!output->outfile)
		return (free_args_d(output));
	output->envp = envp;
	return (output);
}

t_argv	*get_program_argv(char *argv[])
{}