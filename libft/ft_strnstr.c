/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:47:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 18:37:00 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	unsigned int	i;	
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0' || !needle)
		return (haystack);
	if (haystack[0] == '\0' || !haystack || len == 0 )
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len
			&& needle[j] != '\0' && haystack[j] != '\0')
			j++;
		if (needle[j] == '\0')
			break ;
		j = 0;
		i++;
	}
	if (haystack[i] == '\0' || i == len)
		return (NULL);
	return (&haystack[i]);
}
