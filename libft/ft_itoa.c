/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:58:04 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/05 14:35:42 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoaconvert(long int nbr, char *str, int sign, int count)
{
	int			i;

	i = count - 1;
	str[count] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (i > 0)
	{
		if (nbr >= 10)
		{
			str[i] = nbr % 10 + 48;
			nbr = nbr / 10;
		}
		else
			str[i] = nbr % 10 + 48;
		i--;
	}
	if (sign == -1)
		str[i] = '-';
	else
	{
		str[0] = nbr % 10 + 48;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			count;
	long int	nbr;
	int			sign;

	count = 1;
	nbr = nb;
	sign = 1;
	if (nbr < 0)
	{
		count ++;
		nbr *= -1;
		sign = -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	return (ft_itoaconvert((long int)nb, str, sign, count));
}
