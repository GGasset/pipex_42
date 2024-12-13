/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:19:25 by germangasse       #+#    #+#             */
/*   Updated: 2024/11/27 15:27:46 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_args_d(t_args_d *args)
{
	if (!args)
		return (0);
	if (args->infile)
		free(args->infile);
	if (args->program1)
		free(args->program1);
	if (args->program2)
		free(args->program2);
	if (args->outfile)
		free(args->outfile);
	free(args);
	return (0);
}

void	*free_argv(t_argv *argv)
{
	if (!argv)
		return (0);
	if (argv->argv1)
		ft_free_splitted(argv->argv1);
	if (argv->argv2)
		ft_free_splitted(argv->argv2);
	free(argv);
	return (0);
}
