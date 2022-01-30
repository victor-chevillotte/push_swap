/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:03:02 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 15:33:11 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnum(char **numlist, char *num, int piletop)
{
	int	i;
	int	numberofnum;
	int numi;
	
	numi = ft_atoi(num);
	i = 0;
	numberofnum = 0;
	while (i < piletop)
	{
		if (ft_atoi(numlist[i]) == numi)
			numberofnum++;
		i++;
	}
	return (numberofnum);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isprint(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkargs(int piletop, char **argv)
{
	int		i;
	char	*itoa;

	i = 0;
	while (argv[i])
	{
		itoa = ft_itoa(ft_atoi(argv[i]));
		if ((ft_strncmp(argv[i], itoa, ft_strlen(itoa)) != 0 && ft_atoi(argv[i]) != 0)
			|| ft_isnum(argv[i]) != 0 || ft_findnum(argv, argv[i], piletop) > 1)
		{
			free(itoa);
			return (1);
		}
		else
			free(itoa);
		i++;
	}
	return (0);
}

int ft_sizeof(char **argv)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		i++;
	}
		
	return (i);
}

int	ft_init_pushswap(int argc, char **argv, t_pile *pila, t_pile *pilb)
{
	int		i;
	char	**tab;
	int		*tmp;
	int		*tmpnotsorted;
	int		j;

	i = 0;
	j = 0;
	if (argc == 1)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab)
			return (1);
		argc = ft_sizeof(tab);
	}
	else 
		tab = &argv[1];
	if (ft_checkargs(argc, tab) == 1)
		return (1);
	tmpnotsorted = malloc(sizeof(int) * (argc));
	if (!tmpnotsorted)
		return (1);
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		return (1);
	pila->piletop = argc - 1;
	pila->letter = 'A';
	pila->list = malloc(sizeof(int) * (pila->piletop + 1));
	if (!(pila->list))
		return (1);
	pilb->piletop = -1;
	pilb->letter = 'B';
	pilb->list = malloc(sizeof(int) * (pila->piletop + 1));
	if (!(pilb->list))
		return (1);
	i = argc - 1;
	while (i >= 0)
	{
		tmp[argc - i - 1] = ft_atoi(tab[i]);
		tmpnotsorted[argc - i - 1] = ft_atoi(tab[i]);
		i--;
	}
	/*i = pila->piletop + 1;
	while (--i >= 0) *int non triee
	{
		ft_putnbr_fd(tmpnotsorted[i], 1);
		ft_putchar_fd('\n', 1);
	}*/
		quick_sort(tmp, argc);

	/*i = 0;
	while (i < pila->piletop) *int triee
	{
		ft_putnbr_fd(tmp[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}*/
	j = 0;
	i = 0;
	while (i < argc)
	{
		while (j < argc)
		{
			if (tmp[j] == tmpnotsorted[i])
				pila->list[i] = j;
			j++;
		}
		j = 0;
		i++;
	}	
	free(tmpnotsorted);
	free(tmp);
	return (0);
}
