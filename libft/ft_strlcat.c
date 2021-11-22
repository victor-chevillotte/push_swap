/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:20:21 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/03 15:39:54 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	realsizedst;

	if (!src)
		return (ft_strlen(dst));
	realsizedst = 0;
	while (dst[realsizedst] && realsizedst < dstsize)
		realsizedst++;
	if (realsizedst >= dstsize)
		return (dstsize + ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	while (src[j] != '\0' && i + j < dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (realsizedst + ft_strlen(src));
}
