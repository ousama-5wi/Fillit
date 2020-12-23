/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:47:44 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/11 16:28:37 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_tetriminos(const int fd, t_tet *tetri)
{
	int		i;
	char	c;
	char	k;

	c = '\0';
	k = '\0';
	i = 0;
	while (i < 4)
	{
		if (read(fd, tetri->tab[i], 4) != 4)
			return (-1);
		if (ft_chr(tetri->tab[i]) != 0)
			return (-1);
		if (read(fd, &c, 1) != 1)
			return (-1);
		if (c != '\n')
			return (-1);
		i++;
	}
	if (read(fd, &k, 1) == 0)
		return (0);
	if (k != '\n')
		return (-1);
	return (1);
}

void		initialiser(int *i, int *c, int *k)
{
	*i = 0;
	*c = 0;
	*k = 0;
}

int			get_all_tetriminos(const int fd, t_tet **origin)
{
	int		ret;
	t_tet	*tetri;
	int		i;

	i = 0;
	ft_new(&tetri);
	*origin = tetri;
	while ((ret = get_tetriminos(fd, tetri)) == 1)
	{
		ft_new(&tetri->next);
		tetri = tetri->next;
	}
	if (ret == -1)
		return (-1);
	return (1);
}

int			conect(t_tet *tetri, int i, int j, int c)
{
	int		count;

	count = 0;
	(i < 3 && tetri->tab[i + 1][j] == '#') ? count++ : count;
	(i > 0 && tetri->tab[i - 1][j] == '#') ? count++ : count;
	(j < 3 && tetri->tab[i][j + 1] == '#') ? count++ : count;
	(j > 0 && tetri->tab[i][j - 1] == '#') ? count++ : count;
	tetri->x[c] = i;
	tetri->y[c] = j;
	return (count);
}

int			place(t_tet *tetri)
{
	t_zero	var;

	while (tetri)
	{
		initialiser(&var.i, &var.c, &var.k);
		while (tetri->tab[var.i])
		{
			var.j = 0;
			while (tetri->tab[var.i][var.j])
			{
				if (tetri->tab[var.i][var.j] == '#')
				{
					var.k = var.k + conect(tetri, var.i, var.j, var.c);
					if (conect(tetri, var.i, var.j, var.c++) == 0)
						return (-1);
				}
				var.j++;
			}
			var.i++;
		}
		if (!(var.k == 6 || var.k == 8))
			return (-1);
		tetri = tetri->next;
	}
	return (1);
}
