/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:47:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 12:45:46 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	while (s[i] != c && i != 0)
		i--;
	if ((unsigned char)s[i] == (unsigned char)c)
		return (&s[i]);
	return (NULL);
}
