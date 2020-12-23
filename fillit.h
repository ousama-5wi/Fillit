/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:06:33 by oelkhams          #+#    #+#             */
/*   Updated: 2019/07/14 00:40:22 by oelkhams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tet
{
	char			**tab;
	int				x[4];
	int				y[4];
	int				min[2];
	int				max[2];
	struct s_tet	*next;
}					t_tet;

typedef struct		s_map
{
	char			**map;
	int				taille_map;
	int				*x;
	int				*y;
}					t_map;

typedef	struct		s_zero
{
	int				i;
	int				j;
	int				c;
	int				k;
}					t_zero;

int					ft_chr(char *line);
void				ft_new(t_tet **tetri);
int					get_tetriminos(const int fd, t_tet *tetri);
int					get_all_tetriminos(const int fd, t_tet **origin);
int					nbr_hash(t_tet *tetri);
int					conect(t_tet *tetri, int i, int j, int c);
int					place(t_tet *tetri);
int					compt_map(t_map *carta);
int					search_map(t_map *carta);
int					is_tetriminos(t_tet *tetri, t_map *carta, int i, int j);
void				put_tetriminos(t_tet *tetri, t_map *carta, int i, int j);
void				maximal_after(t_tet *origine);
void				minimal(t_tet *origine);
void				ecraz(t_tet *origin);
char				*p_malloc(int i);
void				first_map(int nbt, t_map *carta);
void				free_all(t_tet *origin);
void				free_map(t_map *carta);
int					ft_taille_tet(t_tet *lst);
void				remove_tet(t_tet *tetri, t_map *carta);
int					minim_dim(int nbt);
void				search_map_2(t_map *carta);
#endif
