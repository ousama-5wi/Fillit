/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 00:43:05 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/19 16:37:45 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpdst;
	unsigned char	*cpsrc;

	i = 0;
	cpsrc = (unsigned char *)src;
	cpdst = (unsigned char *)dst;
	while (i < n)
	{
		cpdst[i] = cpsrc[i];
		i++;
		if (cpdst[i - 1] == (unsigned char)c)
			return (cpdst + i);
	}
	return (NULL);
}
