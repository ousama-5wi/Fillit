/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:20:49 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/20 14:22:41 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char *nvs;

	i = 0;
	nvs = s;
	while (i < n)
	{
		if ((unsigned char)c == nvs[i])
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
