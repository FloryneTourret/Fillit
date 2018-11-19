/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 14:08:04 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 18:17:08 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][size] = '\0';
		i++;
	}
	map[size] = NULL;
	return (map);
}

void	free_content(char **content)
{
	int	i;

	i = 0;
	while (content[i++])
		free(content[i]);
	free(content);
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
