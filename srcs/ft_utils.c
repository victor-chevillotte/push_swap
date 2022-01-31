/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:35 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 10:05:58 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printpile(t_pile *pile)
{
	int	i;

	i = pile->piletop + 1;
	while (--i >= 0)
	{
		ft_putnbr_fd(pile->list[i], 2);
		ft_putchar_fd('\n', 2);
	}
}

int	ft_pushswap_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}
