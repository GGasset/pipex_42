/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:16:22 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/11 13:34:32 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*replace_start(char *s, char *old, char *new, char free_s)
{
	char	*out;

	if (s && (!old || !new))
	{
		out = ft_strdup(s);
		if (free_s)
			free(s);
		return (out);
	}
	if (!s || !old || !new)
		return (0);
	if (ft_strnstr(s, old, -2) == s)
		out = ft_strjoin(new, s + ft_strlen(old));
	else
		out = ft_strdup(s);
	if (free_s && s)
		free(s);
	return (out);
}

void	substr_free(char **s, unsigned int start, unsigned int len)
{
	char	*tmp;

	tmp = ft_substr(*s, start, len);
	free(*s);
	*s = tmp;
}
