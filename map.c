/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 14:08:04 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 14:16:30 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size)
{
	int		i;
	char	**map;

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

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		ft_putstr(map[i++]);
	free_map(map);
}
