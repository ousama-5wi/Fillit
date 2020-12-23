/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:01:11 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/11 22:38:39 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_all(t_tet *origin)
{
	int		i;
	t_tet	*tmp;

	while (origin)
	{
		i = 0;
		while (i < 4)
			free(origin->tab[i++]);
		free(origin->tab);
		tmp = origin;
		origin = origin->next;
		free(tmp);
	}
}

void		free_map(t_map *carta)
{
	int		i;

	i = 0;
	while (carta->map[i])
		free(carta->map[i++]);
	free(carta->map);
	free(carta->x);
	free(carta->y);
}

int			ft_taille_tet(t_tet *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
