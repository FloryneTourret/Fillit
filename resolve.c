/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 19:51:20 by ftourret    ###    #+. /#+    ###.fr     */
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
	map = create_map(map, size);
	while (solver(map, tetros, id, nbr_tetros) == 1)
	{
		free_map(map);
		map = create_map(map, size++);
	}
	return (map);
}

char	**create_map(char **map, int size)
{
	int		i;

	i = 0;
	if ((map = (char **)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		map[i][size] = '\0';
		i++;
	}
	map[size] = NULL;
	return (map);
}

int		solver(char **map, char **tetros, int id, int nbr_tetros)
{
	//return 1 si ca marche pas
	//return 0 si ca marche
	//GROS BACKTRACKING EN RECURSIF
	map = NULL;
	ft_putsstr(tetros, nbr_tetros);
	id = 0;
	nbr_tetros = 0;
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
}

void	ft_putsstr(char **str, int nb)
{
	int i;

	i = 0;
	while (i <= nb)
	{
		ft_putstr(str[i]);
		if (i != nb)
			ft_putchar('\n');
		i++;
	}
}
