/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 14:08:04 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 17:35:38 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	if ((map = (char **)malloc(sizeof(char*) * size + 1)) == NULL)
		return (NULL);
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
