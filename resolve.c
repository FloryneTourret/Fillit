/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:38:10 by ftourret    ###    #+. /#+    ###.fr     */
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
	return (map);
}

int	resolve(char **map, char **tetros, int size, int nb_tetros)
{
	int		id;
	t_tetro	*tetro;

	id = -1;
	map = NULL;
	size = 0;
	while (++id <= nb_tetros)
		tetro = coord(tetros, id, -1, 0);
	free(tetro);
	return (0);
}

