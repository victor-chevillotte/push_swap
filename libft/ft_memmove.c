/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:33:39 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 13:40:07 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*chardst;
	unsigned char	*charsrc;

	i = 0;
	chardst = (unsigned char *) dst;
	charsrc = (unsigned char *) src;
	if (!dst || !src)
		return (NULL);
	if (src > dst)
	{
		while (i < len)
		{
			chardst[i] = charsrc[i];
			i++;
		}	
		return (dst);
	}
	i = len;
	while (i-- > 0)
	{
		chardst[i] = charsrc[i];
	}	
	return (dst);
}
