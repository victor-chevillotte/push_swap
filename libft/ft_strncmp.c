/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:47:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 13:00:47 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	i = 0;
	s1u = (unsigned char *) s1;
	s2u = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (s1u[i] != '\0' && s2u[i] != '\0' && i < n && s1u[i] == s2u[i])
		i++;
	if (i == n)
		i--;
	return (s1u[i] - s2u[i]);
}
