/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:50:20 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 13:04:42 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*charc;

	i = 0;
	charc = (unsigned char *) s;
	while (i < n)
	{
		if (charc[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
