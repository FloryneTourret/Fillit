/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:57:36 by ftourret    ###    #+. /#+    ###.fr     */
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
		free_content(map);
		map = create_map(size++);
	}
	ft_putsstr(map, size);
	return (map);
}

int	resolve(char **map, char **tetros, int size, int nb_tetros)
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
		if (is_free(map, tetro) == 0)
			ft_putstr("Free\n");
		else
			ft_putstr("Pas free\n");
		// verifier si il y a la place sur la map
		// si il y a la place placer, sinon decaler
	}
	free(tetro);
	size = 0;
	return (0);
}

int		is_free(char **map, t_tetro *tetro)
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
			else
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
	return (1);
}
