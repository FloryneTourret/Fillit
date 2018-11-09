/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 18:39:20 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*resolve_tetro(char **tetros, int nbr_tetros)
{
	char	*map;
	int		size;

	size = calcul_size();
	map = map_new(size);
	while (!solver(map, tetros))
	{
		free_map(map);
		map = map_new(size++);
	}
	return (map);
}
