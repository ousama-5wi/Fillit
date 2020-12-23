/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:32:31 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/19 16:06:50 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cps1;

	i = ft_strlen(s1) + 1;
	if (!(cps1 = (char*)malloc(i * sizeof(char))))
	{
		return (NULL);
	}
	ft_strcpy(cps1, s1);
	return (cps1);
}
