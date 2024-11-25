/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:04:22 by ggasset-          #+#    #+#             */
/*   Updated: 2024/11/22 11:57:09 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// If is a path (contains any /) and it doesn't start with / add ./ at the begining
// Substitute any ./ with $PWD/
// Otherwise:
//	Search path by trying to open files and look at errors
static char	*get_path(char *path, char *envp[])
{
	char	*is_path;

	path = ft_substr()
	is_path = ft_strchr(path, '/');
	if (is_path && is_path != path)
		ft_strjoin('./', path);
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

static void	fill_argv(size_t program_n, t_argv *args, char *argv[])
{
	char	**prog_argv;
	char	*to_parse;
	char	*tmp;
	char	*tmp2;

	to_parse = argv[2 + program_n];
	tmp = ft_strchr(to_parse, '/') + 1;
	tmp2 = ft_strchr(to_parse, ' ') + 1;
	if ((!tmp2 && tmp) || (tmp < tmp2 && !tmp && !tmp2))
		to_parse = tmp;
	prog_argv = ft_split(to_parse, ' ');
	*((&args->argv1) + program_n) = prog_argv;
}

t_argv	*get_program_argv(char *argv[])
{
	t_argv	*out;
	
	out = malloc(sizeof(t_argv));
	if (!out)
		return (0);
	ft_bzero(out, sizeof(t_argv));
	fill_argv(0, out, argv);
	fill_argv(1, out, argv);
	if (!out->argv1 || !out->argv2)
	{
		ft_free_splitted(out->argv1);
		ft_free_splitted(out->argv2);
		free(out);
		out = 0;
	}
	return (out);
}
