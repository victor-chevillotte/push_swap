/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:20 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 16:26:31 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_pile(t_pile *pile)
{
	int	tmp;

	if (pile->piletop < 2)
		return ;
	tmp = pile->list[0];
	pile->list[0] = pile->list[1];
	pile->list[1] = tmp;
}

void	ft_rotate_pile(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->piletop < 1)
		return ;
	tmp = pile->list[0];
	i = -1;
	while (++i < pile->piletop)
		pile->list[i] = pile->list[i + 1];
	pile->list[i] = tmp;
}

void	ft_rotate_reverse_pile(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->piletop < 1)
		return ;
	tmp = pile->list[pile->piletop];
	i = pile->piletop + 1;
	while (--i > 0)
		pile->list[i] = pile->list[i - 1];
	pile->list[0] = tmp;
}
