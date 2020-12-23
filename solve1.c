/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:03:58 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/12 20:35:27 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		maximal_after(t_tet *origine)
{
	int		i;
	int		maxy;
	int		maxx;

	while (origine)
	{
		maxx = origine->x[0];
		maxy = origine->y[0];
		i = 1;
		while (i < 4)
		{
			if (origine->x[i] > maxx)
				maxx = origine->x[i];
			if (origine->y[i] > maxy)
				maxy = origine->y[i];
			i++;
		}
		origine->max[0] = maxx;
		origine->max[1] = maxy;
		origine = origine->next;
	}
}

void		minimal(t_tet *origine)
{
	int		i;
	int		miny;
	int		minx;

	while (origine)
	{
		minx = origine->x[0];
		miny = origine->y[0];
		i = 1;
		while (i < 4)
		{
			if (origine->x[i] < minx)
				minx = origine->x[i];
			if (origine->y[i] < miny)
				miny = origine->y[i];
			i++;
		}
		origine->min[0] = minx;
		origine->min[1] = miny;
		origine = origine->next;
	}
}

void		ecraz(t_tet *origin)
{
	int		i;
	char	c;
	int		a;
	int		b;

	c = 'A';
	while (origin)
	{
		i = 0;
		while (i < 4)
		{
			origin->tab[origin->x[i]][origin->y[i]] = '.';
			a = origin->x[i] - origin->min[0];
			b = origin->y[i] - origin->min[1];
			origin->tab[a][b] = c;
			origin->x[i] = origin->x[i] - origin->min[0];
			origin->y[i] = origin->y[i] - origin->min[1];
			i++;
		}
		origin = origin->next;
		c++;
	}
}

char		*p_malloc(int i)
{
	int		j;
	char	*s;

	j = 0;
	s = (char *)malloc(i + 1);
	if (s == NULL)
		return (NULL);
	while (j < i)
		s[j++] = '.';
	s[i] = '\0';
	return (s);
}

void		first_map(int dim, t_map *carta)
{
	int		j;

	j = 0;
	if (!(carta->map = (char**)malloc(sizeof(char *) * (dim + 1))))
		return ;
	while (j < dim)
		if (!(carta->map[j++] = p_malloc(dim)))
			return ;
	carta->map[dim] = NULL;
}
