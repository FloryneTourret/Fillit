/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:26:11 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**resolve_tetro(char **tetros, int nbr_tetros)
{
	char	**map;
	int		size;
	int		id;

	size = 4;
	id = 0;
	map = create_map(size);
	while (solver(map, tetros, id, nbr_tetros) == 1)
	{
		free_map(map);
		map = create_map(size++);
	}
	return (map);
}

/*
/** Solveur récursif, essaye de placer un tetro a une position de la map, si pas possible essaye avec le tetro suivant
*/

int		solver(char **map, char **tetros, int id, int nbr_tetros)
{
	int	x;
	int	y;

	y = 0;
	if (tetros[id] == NULL)
		return (1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (place_tetri(tetros[id], map, x, y) == 0)
			{
				if (solver(map, tetros, id + 1, nbr_tetros) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		place_tetri(char *tetros, char **map, int x, int y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (tetros[i])
	{
		k = 0;
		while (tetros[i] != '\n')
		{
			if (tetros[i] != '.')
			{
				if (map[y + j][x + k] == '.')
					map[y + j][x + k++] = tetros[i];
				else
					return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
