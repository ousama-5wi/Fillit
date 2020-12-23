/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 01:40:34 by oelkhams          #+#    #+#             */
/*   Updated: 2019/04/21 01:44:46 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		longmot(int n)
{
	int j;

	j = 0;
	if (n < 0)
		j++;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 10;
		j++;
	}
	return (j + 1);
}

static	char	*caszero(char *c)
{
	c[0] = '0';
	return (c);
}

static	int		casnegative(char *c, int n)
{
	c[0] = '-';
	return (-n);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = longmot(n);
	c = (char *)malloc(i);
	if (!c)
		return (NULL);
	c[i - 1] = '\0';
	if (n < 0)
		n = casnegative(c, n);
	else if (n == 0)
		return (caszero(c));
	c = c + i - 1;
	while (n != 0)
	{
		c--;
		*c = n % 10 + '0';
		n = n / 10;
	}
	if (*(c - 1) == '-')
		return (c - 1);
	return (c);
}
