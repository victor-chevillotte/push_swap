/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:50:20 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/03 11:46:28 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*chardst;
	unsigned char	*charsrc;

	i = 0;
	if (!src)
		return (dst);
	chardst = (unsigned char *) dst;
	charsrc = (unsigned char *) src;
	while (i < n)
	{
		chardst[i] = charsrc[i];
		i++;
	}
	return (dst);
}
