/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:00:22 by mdesoeuv          #+#    #+#             */
/*   Updated: 2021/12/03 11:58:52 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_swap(int *a, int *b)
{
	int tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}

int	fill_tab(int **tab, int argc, char **argv)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 1;
	size = argc - 1;
	*tab = malloc(sizeof(int) * size);
	if (!*tab)
		return (-1);
	while (i < argc - 1)
	{
		(*tab)[i++] = ft_atoi(argv[j++]);
	}
	return (size);
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
