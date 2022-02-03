/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:29:24 by vchevill          #+#    #+#             */
/*   Updated: 2022/02/03 13:43:21 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_splitoneword(int start, int end, char const *s)
{
	char	*word;
	int		j;

	j = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!word)
		return (NULL);
	while (start + j <= end)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_splitmalloc(char const *s, char c)
{
	int		nbrword;
	int		i;
	char	**dest;

	nbrword = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbrword++;
		i++;
	}
	dest = (char **)malloc((nbrword + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	return (dest);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		numword;
	char	**dest;

	i = -1;
	j = 0;
	numword = 0;
	dest = ft_splitmalloc(s, c);
	if (!dest)
		return (NULL);
	while (s[++i] != '\0')
	{	
		if (s[i] == c && s[i + 1] != c)
			j = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			dest[numword] = ft_splitoneword(j, i, s);
			if (!dest[numword++])
				return (NULL);
			j = i + 2;
		}
	}
	dest[numword] = 0;
	return (dest);
}
