/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:48:59 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/18 19:51:53 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *dest)
{
	int i;
	int j;

	i = 0;
	if (dest[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == dest[j]) && ((str[i + j]) && (dest[j])))
			j++;
		if (dest[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
