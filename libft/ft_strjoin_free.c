/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germangasset <germangasset@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:07:06 by germangasse       #+#    #+#             */
/*   Updated: 2024/11/20 16:48:24 by germangasse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Perfect to append file contents to a buffer
char	*ft_strjoin_free(char const *s1, char const *s2, int free1, int free2)
{
	char	*out;
	
	out = ft_strjoin(s1, s2);
	if (s1 && !s2)
		out = ft_strdup(s1);
	if (!s1 && s2)
		out = ft_strdup(s2);
	if (s1 && free1)
		free(s1);
	if (s2 && free2)
		free(s2);
	return (out);
}
