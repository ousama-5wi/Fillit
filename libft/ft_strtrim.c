/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 00:37:31 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/21 01:51:54 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*c;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == j + 1)
	{
		c = (char *)malloc(1);
		*c = '\0';
		return (c);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	c = (char *)malloc(j - i + 2);
	if (c == NULL)
		return (NULL);
	ft_memmove(c, s + i, j - i + 1);
	c[j - i + 1] = '\0';
	return (c);
}
