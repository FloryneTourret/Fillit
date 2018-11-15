/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetros.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:37:00 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 19:52:40 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetro		*coord(t_tetro *tetro, char **tetros, int id)
{
	int		i;
	int		found;
	int		x;
	int		y;

	x = -1;
	y = 0;
	i = -1;
	found = 0;
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
	tetro->letter = id + 65;
	return (tetro);
}

void		stock_tetro(t_tetro *tetro, int x, int y, int found)
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

int			min(int val1, int val2, int val3, int val4)
{
	int		tab[4];

	tab[0] = val1;
	tab[1] = val2;
	tab[2] = val3;
	tab[3] = val4;
	sort_int_tab(tab, 4);
	return (tab[0]);
}

void		serialize_tetro(t_tetro *tetro)
{
	int xmin;
	int ymin;

	xmin = min(tetro->x1, tetro->x2, tetro->x3, tetro->x4);
	ymin = min(tetro->y1, tetro->y2, tetro->y3, tetro->y4);
	tetro->x1 -= xmin;
	tetro->y1 -= ymin;
	tetro->x2 -= xmin;
	tetro->y2 -= ymin;
	tetro->x3 -= xmin;
	tetro->y3 -= ymin;
	tetro->x4 -= xmin;
	tetro->y4 -= ymin;
}

int	read_tetros(int fd, int id, char **tetros)
{
	char		buf[21 + 1];
	int			ret;

	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (check_tetro(buf, id) == 0)
		{
			if (!(tetros[id] = ft_strsub(buf, 0, 21)))
				ft_error();
		}
		else
			ft_error();
		id++;
	}
	tetros[id] = NULL;
	if (id == 0 || tetros[id - 1][20] != '\0')
		ft_error();
	return (id);
}
