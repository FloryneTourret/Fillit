/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 17:58:07 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*resolve_tetro(char **tetros, int nbr_tetros)
{
	char	*map;
	int		finish;
	int		i;

	i = 0;
	while (i < nbr_tetros)
	{
		finish = 0;

		if (put_tetro(map, tetros[i]) == 0)
			i++;
	}
	map = tetros[25];
	return (map);
}

void	ft_putstr(char str, int i)
{
	write(1, &str[i], 1);
	ft_putstr(str, i + 1);
}
