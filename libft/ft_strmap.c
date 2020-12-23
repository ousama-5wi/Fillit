/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:05:22 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/19 23:04:07 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	char	*str;
	char	*cps;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	cps = (char *)s;
	while (s[i])
	{
		str[i] = f(cps[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
