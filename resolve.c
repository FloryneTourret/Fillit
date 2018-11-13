/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 21:05:52 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**resolve_tetro(char **tetros, int nb_tetros)
{
	char	**map;
	int		size;

	size = 4;
	map = create_map(size);
	while (resolve(map, tetros, size, nb_tetros) == 1)
	{
		ft_putstr("Nouvelle map\n");
		free_content(map);
		size++;
		map = create_map(size);
	}
	ft_putsstr(map, size);
	ft_putstr("FINI\n");
	return (map);
}

int		resolve(char **map, char **tetros, int size, int nb_tetros)
{
	int		id;
	t_tetro	*tetro;

	id = -1;
	while (++id <= nb_tetros)
	{
		if ((tetro = malloc(sizeof(t_tetro))) == NULL)
			return (1);
		coord(tetro, tetros, id);
		serialize_tetro(tetro);
		if (is_free(map, tetro, size) == 0)
		{
			ft_putstr("Place\n");
		}
		else
			return (1);
	}
	free(tetro);
	return (0);
}

int		is_free(char **map, t_tetro *tetro, int size)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((place_tetro(map, tetro, x, y) == 0))
				return (0);
			if (y == size - 1 && x == size - 1)
				return (1);
			x++;
			if (map[y][x] == '\0')
			{
				x = 0;
				y++;
			}
		}
	}
	return (1);
}

int		place_tetro(char **map, t_tetro *tetro, int x, int y)
{
	int size;

	size = ft_strlen(map[0]);
	if ((y + tetro->y1 < size) && (y + tetro->y2 < size)
	&& (y + tetro->y3 < size) && (y + tetro->y4 < size)
	&& (x + tetro->x1 < size) && (x + tetro->x2 < size)
	&& (x + tetro->x3 < size) && (x + tetro->x4 < size))
	{
		if (map[y + tetro->y1][x + tetro->x1] == '.'
		&& map[y + tetro->y2][x + tetro->x2] == '.'
		&& map[y + tetro->y3][x + tetro->x3] == '.'
		&& map[y + tetro->y4][x + tetro->x4] == '.')
		{
			map[y + tetro->y1][x + tetro->x1] = tetro->letter;
			map[y + tetro->y2][x + tetro->x2] = tetro->letter;
			map[y + tetro->y3][x + tetro->x3] = tetro->letter;
			map[y + tetro->y4][x + tetro->x4] = tetro->letter;
			return (0);
		}
	}
	return (1);
}
