/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parte1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:03:06 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/13 17:16:31 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_new(t_tet **tetri)
{
	int		i;

	i = 0;
	if ((*tetri = (t_tet *)malloc(sizeof(t_tet))))
	{
		(*tetri)->tab = (char **)malloc(sizeof(char *) * 5);
		while (i < 4)
			(*tetri)->tab[i++] = ft_strnew(5);
		(*tetri)->tab[i] = NULL;
		(*tetri)->next = NULL;
	}
}

int			ft_chr(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (1);
		i++;
	}
	return (0);
}

int			nbr_hash(t_tet *tetri)
{
	int		i;
	int		j;
	int		compt;

	while (tetri)
	{
		i = 0;
		compt = 0;
		while (tetri->tab[i])
		{
			j = 0;
			while (tetri->tab[i][j])
			{
				if (tetri->tab[i][j] == '#')
					compt++;
				j++;
			}
			i++;
		}
		if (compt != 4)
			return (-1);
		tetri = tetri->next;
	}
	return (1);
}

void		remove_tet(t_tet *tetri, t_map *carta)
{
	char	c;
	int		i;
	int		j;

	c = tetri->tab[tetri->x[0]][tetri->y[0]];
	i = 0;
	while (carta->map[i])
	{
		j = 0;
		while (carta->map[i][j])
		{
			if (carta->map[i][j] == c)
				carta->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			minim_dim(int nbt)
{
	int i;

	i = 2;
	while (i * i < nbt * 4)
		i++;
	return (i);
}
