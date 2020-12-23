/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:45:23 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/16 19:04:35 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(t_tet *tetri, t_map *carta)
{
	int		i;
	int		j;

	i = 0;
	if (tetri == NULL)
		return (1);
	while (carta->map[i])
	{
		j = 0;
		while (carta->map[i][j])
		{
			if (is_tetriminos(tetri, carta, i, j) == 1)
			{
				put_tetriminos(tetri, carta, i, j);
				if (solve(tetri->next, carta))
					return (1);
				else
					remove_tet(tetri, carta);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		main_2(t_tet *tetri)
{
	if (nbr_hash(tetri) != 1)
	{
		ft_putendl("error");
		exit(0);
	}
	if (place(tetri) != 1)
	{
		ft_putendl("error");
		exit(0);
	}
	minimal(tetri);
	ecraz(tetri);
	maximal_after(tetri);
}

void		main_3(t_tet *tetri, t_map *carta, int dim)
{
	int		i;

	while (solve(tetri, carta) == 0)
	{
		i = 0;
		while (carta->map[i])
			free(carta->map[i++]);
		free(carta->map);
		dim++;
		first_map(dim, carta);
		carta->taille_map = ft_strlen(carta->map[0]);
	}
	i = 0;
	while (carta->map[i])
		ft_putendl(carta->map[i++]);
	if (dim == 2 || dim == 3)
	{
		i = 0;
		while (carta->map[i])
			free(carta->map[i++]);
		free(carta->map);
	}
	else
		free_map(carta);
}

int			main(int ac, char **av)
{
	t_tet	*tetri;
	int		fd;
	int		dim;
	t_map	*carta;

	tetri = NULL;
	carta = NULL;
	(ac != 2) ? ft_putendl("usage: ./fillit input_file") : ac;
	(ac != 2) ? exit(0) : ac;
	fd = open(av[ac - 1], O_RDONLY);
	if (get_all_tetriminos(fd, &tetri) != 1)
	{
		ft_putendl("error");
		exit(0);
	}
	main_2(tetri);
	carta = (t_map *)malloc(sizeof(t_map));
	dim = minim_dim(ft_taille_tet(tetri));
	first_map(dim, carta);
	carta->taille_map = ft_strlen(carta->map[0]);
	main_3(tetri, carta, dim);
	free_all(tetri);
	free(carta);
	return (0);
}
