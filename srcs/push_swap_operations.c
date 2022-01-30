/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:20 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 16:42:40 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_pile(t_pile *pila, t_pile *pilb, t_letter letter)
{
	ft_putchar_fd('s', 1);
	ft_putchar_fd(letter, 1);
	if (letter == a)
	{
		ft_putchar_fd('a', 1);
		ft_swap_pile_f(pila);
	}
	else if (letter == b)
	{
		ft_putchar_fd('b', 1);
		ft_swap_pile_f(pilb);
	}
	else
	{
		ft_putchar_fd('s', 1);
		ft_swap_pile_f(pila);
		ft_swap_pile_f(pilb);
	}
	ft_putchar_fd('\n', 1);
}

void	ft_swap_pile_f(t_pile *pile)
{
	int	tmp;

	if (pile->piletop < 2)
		return ;
	tmp = pile->list[0];
	pile->list[0] = pile->list[1];
	pile->list[1] = tmp;
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

void	ft_rotate_reverse_pile_f(t_pile *pile)
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

void	ft_rotate_pile_f(t_pile *pile)
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

void	ft_push_pile(t_pile *pila, t_pile *pilb, t_letter letter)
{

	ft_putchar_fd('p', 1);
	if (letter == a)
	{
		ft_push_pile_f(pilb, pila);
		ft_putchar_fd('a', 1);
	}
	else
	{
		ft_push_pile_f(pila, pilb);
		ft_putchar_fd('b', 1);
	}
	ft_putchar_fd('\n', 1);
}

void	ft_push_pile_f(t_pile *pile_rem, t_pile *pile_add)
{
	int		num_to_swap;

	if (pile_rem->piletop < 0)
		return ;
	num_to_swap = pile_rem->list[pile_rem->piletop];
	pile_rem->piletop--;
	pile_add->piletop++;
	pile_add->list[pile_add->piletop] = num_to_swap;
}
