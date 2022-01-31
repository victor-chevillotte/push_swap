/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_rotatations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:20 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 22:50:26 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_rotate_pile_f(t_pile *pile)
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

void	ft_rotate_pile(t_pile *pila, t_pile *pilb, t_letter letter)
{
	ft_putchar_fd('r', 1);
	if (letter == a)
	{
		ft_putchar_fd('a', 1);
		ft_rotate_pile_f(pila);
	}
	else if (letter == b)
	{
		ft_putchar_fd('b', 1);
		ft_rotate_pile_f(pilb);
	}
	else
	{
		ft_putchar_fd('r', 1);
		ft_rotate_pile_f(pila);
		ft_rotate_pile_f(pilb);
	}
	ft_putchar_fd('\n', 1);
}

void static	ft_rotate_reverse_pile_f(t_pile *pile)
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

void	ft_rotate_reverse_pile(t_pile *pila, t_pile *pilb, t_letter letter)
{
	ft_putchar_fd('r', 1);
	ft_putchar_fd('r', 1);
	if (letter == a)
	{
		ft_putchar_fd('a', 1);
		ft_rotate_reverse_pile_f(pila);
	}
	else if (letter == b)
	{
		ft_putchar_fd('b', 1);
		ft_rotate_reverse_pile_f(pilb);
	}
	else
	{
		ft_putchar_fd('r', 1);
		ft_rotate_reverse_pile_f(pila);
		ft_rotate_reverse_pile_f(pilb);
	}
	ft_putchar_fd('\n', 1);
}
