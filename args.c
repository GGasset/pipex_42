/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:04:22 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/11 13:34:45 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_path(char **file_path)
{
	if (file_exists(*file_path))
		return ;
	free(*file_path);
	*file_path = 0;
}

// If is a path (contains any /) and it doesn't start with / 
//		add ./ at the begining
// Substitute starting ./ if any with $PWD/
// Otherwise:
//	Search path by trying to open files and look at errors
static char	*get_path(char *path, char *envp[], int must_exist)
{
	char	*is_path;
	char	*pwd;
	char	*out;

	pwd = ft_strjoin(get_envp("PWD", envp), "/");
	path = ft_strdup(path);
	if (ft_strchr(path, ' '))
		substr_free(&path, 0, (size_t)ft_strchr(path, ' ') - (size_t)path);
	is_path = ft_strchr(path, '/');
	if (is_path && is_path != path && ft_strchr(path, '~') != path)
		path = ft_strjoin_free("./", path, 0, 1);
	path = replace_start(path, "./", pwd, 1);
	if (is_path)
	{
		free(pwd);
		return (path);
	}
	out = get_from_path(path, envp);
	if (!out)
		out = ft_strjoin(pwd, path);
	if (must_exist)
		check_path(&out);
	free(pwd);
	free(path);
	return (out);
}

t_args_d	*parse_args(int argc, char *argv[], char *envp[])
{
	t_args_d	*output;

	if (argc != 5)
		return (0);
	output = malloc(sizeof(t_args_d));
	if (!output)
		return (0);
	ft_bzero((void *)output, sizeof(t_args_d));
	output->infile = get_path(argv[1], envp, 1);
	if (!output->infile)
		return (free_args_d(output) + 1);
	output->program1 = get_path(argv[2], envp, 1);
	if (!output->program1)
		return (free_args_d(output) + 2);
	output->program2 = get_path(argv[3], envp, 1);
	if (!output->program2)
		return (free_args_d(output) + 3);
	output->outfile = get_path(argv[4], envp, 0);
	if (!output->outfile)
		return (free_args_d(output) + 4);
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
	return (out);
}
