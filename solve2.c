/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:09:14 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/14 00:39:17 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compt_map(t_map *carta)
{
	int	i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (carta->map[i])
	{
		j = 0;
		while (carta->map[i][j])
		{
			if (carta->map[i][j] != '.')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int		search_map(t_map *carta)
{
	if (compt_map(carta) == 0)
		return (0);
	if (carta->x)
	{
		free(carta->x);
		free(carta->y);
	}
	carta->x = (int *)malloc(sizeof(int) * (compt_map(carta)));
	carta->y = (int *)malloc(sizeof(int) * (compt_map(carta)));
	search_map_2(carta);
	return (compt_map(carta));
}

void	search_map_2(t_map *carta)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (carta->map[i])
	{
		j = 0;
		while (carta->map[i][j])
		{
			if (carta->map[i][j] != '.')
			{
				carta->x[k] = i;
				carta->y[k++] = j;
			}
			j++;
		}
		i++;
	}
}

int		is_tetriminos(t_tet *tetri, t_map *carta, int i, int j)
{
	int m;
	int i1;
	int j1;

	search_map(carta);
	m = compt_map(carta);
	i1 = 0;
	if ((tetri->max[0] + i) >= carta->taille_map ||
			(tetri->max[1] + j) >= carta->taille_map)
		return (0);
	while (i1 < 4)
	{
		j1 = 0;
		while (j1 < m)
		{
			if ((tetri->x[i1] + i) == carta->x[j1] &&
					(tetri->y[i1] + j) == carta->y[j1])
				return (0);
			j1++;
		}
		i1++;
	}
	return (1);
}

void	put_tetriminos(t_tet *tetri, t_map *carta, int i, int j)
{
	int i1;
	int j1;

	i1 = 0;
	while (i1 < 4)
	{
		j1 = 0;
		while (j1 < 4)
		{
			if (tetri->tab[i1][j1] != '.')
				carta->map[i1 + i][j1 + j] = tetri->tab[i1][j1];
			j1++;
		}
		i1++;
	}
}
