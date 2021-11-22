/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:47:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 12:48:45 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if ((unsigned char)s[i] == (unsigned char)c)
		return (&s[i]);
	return (NULL);
}
