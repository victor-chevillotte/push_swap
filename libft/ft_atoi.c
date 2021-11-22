/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:47:38 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/04 18:42:48 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longint(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			j;
	long int	nbr;
	long int	sign;

	sign = 1;
	j = 0;
	nbr = 0;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == ' ')
		j++;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(str[j]))
	{
		nbr = nbr * 10 + str[j++] - '0';
		if (nbr > 2147483648)
			return (ft_longint(sign));
	}
	return (nbr * sign);
}
