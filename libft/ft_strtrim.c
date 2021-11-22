/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:40:43 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/08 11:14:38 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	ft_strtriminit(int *i, size_t *size, int *start, int *previsinset)
{
	*i = -1;
	*size = 0;
	*start = -1;
	*previsinset = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	size;	
	int		start;
	int		previsinset;

	if (!s1 || !set)
		return (NULL);
	ft_strtriminit(&i, &size, &start, &previsinset);
	while (s1[++i] != '\0')
	{
		if (!ft_isinset(s1[i], set))
		{
			if (start == -1)
				start = i;
			previsinset = 0;
			size++;
		}
		else if (ft_isinset(s1[i], set) && start != -1 && s1[i] != '\0')
		{
			size ++;
			previsinset++;
		}
	}
	return (ft_substr(s1, start, size - previsinset));
}
