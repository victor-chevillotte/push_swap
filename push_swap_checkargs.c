/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkargs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:03:02 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 13:03:04 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnum(char **numlist, char *num, int length)
{
	int	i;
	int	numberofnum;

	i = 0;
	numberofnum = 0;
	while (i < length)
	{
		if (ft_strncmp(numlist[i], num, ft_strlen(num)) == 0)
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

int	ft_checkargs(int argc, char **argv)
{
	int		i;
	char	*itoa;

	i = 1;
	while (argv[i])
	{
		itoa = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(argv[i], itoa, ft_strlen(itoa)) != 0
			|| ft_isnum(argv[i]) != 0 || ft_findnum(argv, argv[i], argc) > 1)
		{
			free(itoa);
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		else
			free(itoa);
		i++;
	}
	return (0);
}