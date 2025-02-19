/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:16:22 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/27 13:04:52 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*replace_start(char *s, char *old, char *new, char free_s)
{
	char	*out;

	if (!s || !old)
		return (0);
	else if (!new)
		return (s);
	if (ft_strnstr(s, old, -2) == s)
		out = ft_strjoin(new, s + ft_strlen(old));
	else
		out = ft_strdup(s);
	if (free_s && s)
		free(s);
	return (out);
}
