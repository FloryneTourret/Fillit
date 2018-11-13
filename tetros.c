/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetros.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:37:00 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:38:31 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetro		*coord(char **tetros, int id, int x, int y)
{
	int		i;
	int		found;
	t_tetro *tetro;

	i = -1;
	found = 0;
	if ((tetro = malloc(sizeof(t_tetro))) == NULL)
		return (NULL);
	while (tetros[id][++i])
	{
		x++;
		if (tetros[id][i] == '\n')
		{
			y++;
			x = -1;
		}
		if (tetros[id][i] == id + 65)
			stock_tetro(tetro, x, y, found++);
	}
	return (tetro);
}

void	stock_tetro(t_tetro *tetro, int x, int y, int found)
{
	if (found == 0)
	{
		tetro->x1 = x;
		tetro->y1 = y;
	}
	if (found == 1)
	{
		tetro->x2 = x;
		tetro->y2 = y;
	}
	if (found == 2)
	{
		tetro->x3 = x;
		tetro->y3 = y;
	}
	if (found == 3)
	{
		tetro->x4 = x;
		tetro->y4 = y;
	}
}
