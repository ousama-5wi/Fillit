/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:12:34 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/21 23:55:56 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dest;

	i = 0;
	k = 0;
	if (!(str) || !(dest = (char**)malloc((ft_nm(str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (str[k])
	{
		while (str[k] == c && str[k])
			k++;
		if (str[k] && ft_nm(str, c))
		{
			j = 0;
			if (!(dest[i] = (char*)malloc((ft_longmot(str, k, c) + 1))))
				return (NULL);
			while (str[k] != c && str[k])
				dest[i][j++] = str[k++];
			dest[i++][j] = '\0';
		}
	}
	dest[i] = 0;
	return (dest);
}
