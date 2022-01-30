/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:00:22 by mdesoeuv          #+#    #+#             */
/*   Updated: 2022/01/30 20:09:45 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_swap(int *a, int *b)
{
	int	tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

int	swap_from_left(int *tab, int i, int j)
{
	if (i == j)
		return (i);
	while (i < j)
	{
		if (tab[j] < tab[i])
		{	
			ft_swap(&tab[j], &tab[i]);
			return (swap_from_right(tab, i, j - 1));
		}
		i++;
	}
	return (j);
}

int	swap_from_right(int *tab, int i, int j)
{
	if (i == j)
		return (i);
	while (j > i)
	{
		if (tab[j] < tab[i])
		{
			ft_swap(&tab[i], &tab[j]);
			return (swap_from_left(tab, i + 1, j));
		}
		j--;
	}
	return (i);
}

void	quick_sort(int *tab, int size)
{
	int	p;

	if (size < 2)
		return ;
	p = swap_from_right(tab, 0, size - 1);
	quick_sort(&tab[0], p + 1);
	quick_sort(&tab[p + 1], size - (p + 1));
}
