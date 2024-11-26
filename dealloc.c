/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:19:25 by germangasse       #+#    #+#             */
/*   Updated: 2024/11/21 12:07:05 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool		free_args_d(t_args_d *args)
{
	if (args->infile)
		free(args->infile);
	return (0);
}

t_bool		free_argv(t_argv *argv)
{
	
}