/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:52 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 19:06:03 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnum(char **num_tab, char *num)
{
	int	i;
	int	numberofnum;
	int	numi;

	numi = ft_atoi(num);
	i = 0;
	numberofnum = 0;
	while (num_tab[i])
	{
		if (ft_atoi(num_tab[i]) == numi)
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
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkargs(char **num_tab)
{
	int		i;
	char	*itoa;

	i = 0;
	while (num_tab[i])
	{
		itoa = ft_itoa(ft_atoi(num_tab[i]));
		if ((ft_strncmp(num_tab[i], itoa, ft_strlen(itoa)) != 0
				&& ft_strncmp(num_tab[i], itoa, ft_strlen(num_tab[i])) != 0
				&& ft_strncmp(num_tab[i], "-0", ft_strlen(num_tab[i])) != 0
				&& ft_strncmp(num_tab[i], "0", ft_strlen(num_tab[i])) != 0
				&& ft_strncmp(num_tab[i], "+0", ft_strlen(num_tab[i])) != 0)
			|| ft_isnum(num_tab[i]) != 0 || ft_findnum(num_tab, num_tab[i]) > 1)
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

int	ft_sizeof(char **num_tab)
{
	int	i;

	i = 0;
	while (num_tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_match_index(int argc, int *tmp, int *tmpnotsorted, t_pile *pila)
{
	int	i;
	int	j;

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
}