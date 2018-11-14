/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 16:30:52 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**resolve_tetro(char **tetros, t_info *info)
{
	char	**map;

	map = create_map(info->size);
	while (resolve(map, tetros, info) == 1)
	{
		/********************************************************************/
		ft_putstr("Nouvelle map\n");
		/********************************************************************/
		free_content(map);
		info->size++;
		map = create_map(info->size);
	}
	/********************************************************************/
	ft_putsstr(map, info->size);
	ft_putstr("FINI\n");
	/********************************************************************/
	return (map);
}

int		resolve(char **map, char **tetros, t_info *info)
{
	t_tetro	*tetro;

	while (++info->id <= info->nb_tetros)
	{
		/********************************************************************/
		ft_putstr("tetro : ");
		ft_putchar(info->id + 65);
		ft_putchar('\n');
		/********************************************************************/
		if ((tetro = malloc(sizeof(t_tetro))) == NULL)
			return (1);
		coord(tetro, tetros, info->id);
		serialize_tetro(tetro);
		if (check_free(map, tetros, tetro, info) == 0)
			free(tetro);
		else
		{
			info->id = -1;
			info->x = 0;
			info->y = 0;
			return (1);
		}
	}
	return (0);
}

int	check_free(char **map, char **tetros, t_tetro *tetro, t_info *info)
{
	while (map[info->y])
	{
		while (map[info->y][info->x])
		{
			if ((is_free(map, tetro, info->x, info->y) == 0))
			{
				/********************************************************************/
				ft_putstr("place : ");
				ft_putchar(info->id + 65);
				ft_putchar('\n');
				ft_putsstr(map, info->size);
				ft_putchar('\n');
				ft_putchar('\n');
				/********************************************************************/
				return (0);
			}
			if (info->y == info->size - 1 && info->x == info->size - 1
				&& tetro->letter != 'A')
			{
				/********************************************************************/
				ft_putstr("pas la place : ");
				ft_putchar(info->id + 65);
				ft_putchar('\n');
				ft_putsstr(map, info->size);
				ft_putchar('\n');
				ft_putchar('\n');
				/********************************************************************/
				if (backtracking(map, tetros, tetro, info) == 0)
				{
					/********************************************************************/
					ft_putstr("backtracking\n");
					/********************************************************************/
					return (0);
				}
				return (1);
			}
			if (info->y == info->size - 1 && info->x == info->size - 1
				&& tetro->letter == 'A')
			{
				/********************************************************************/
				ft_putstr("pas la place, il faut agrandir : ");
				ft_putchar(info->id + 65);
				ft_putchar('\n');
				ft_putsstr(map, info->size);
				ft_putchar('\n');
				ft_putchar('\n');
				/********************************************************************/
				return (1);
			}
			info->x++;
			/********************************************************************/
			ft_putstr("a droite\n");
			/********************************************************************/
			if (map[info->y][info->x] == '\0')
			{
				/********************************************************************/
				ft_putstr("en dessous\n");
				/********************************************************************/
				info->y++;
				info->x = 0;
			}
		}
	}
	return (1);
}

int		backtracking(char **map, char **tetros, t_tetro *tetro, t_info *info)
{
	t_tetro *before;

	if ((before = malloc(sizeof(t_tetro))) == NULL)
		return (1);
	coord(before, tetros, info->id - 1);
	serialize_tetro(before);
	remove_tetro(map, tetro, info);
	/********************************************************************/
	ft_putstr("je supprime : ");
	ft_putchar(info->id + 65 - 1);
	ft_putchar('\n');
	ft_putsstr(map, info->size);
	ft_putchar('\n');
	ft_putchar('\n');
	/********************************************************************/
	info->found = 0;
	info->x++;
	info->id--;
	if (check_free(map, tetros, before, info) == 0)
	{
		/********************************************************************/
		ft_putstr("je check\n");
		/********************************************************************/
		if ((resolve(map, tetros, info)) == 1)
		{
			/********************************************************************/
			ft_putstr("je dois agrandir : ");
			ft_putchar(info->id + 65);
			ft_putchar('\n');
			ft_putsstr(map, info->size);
			ft_putchar('\n');
			ft_putchar('\n');
			/********************************************************************/
			info->size++;
			resolve_tetro(tetros, info);
		}
		else
			return (0);
	}
	return (1);
}

int		is_free(char **map, t_tetro *tetro, int x, int y)
{
	int size;

	size = ft_strlen(map[0]);
	if ((y + tetro->y1 < size) && (y + tetro->y2 < size)
	&& (y + tetro->y3 < size) && (y + tetro->y4 < size)
	&& (x + tetro->x1 < size) && (x + tetro->x2 < size)
	&& (x + tetro->x3 < size) && (x + tetro->x4 < size))
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
	}
	return (1);
}

void	remove_tetro(char **map, t_tetro *tetro, t_info *info)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == tetro->letter - 1)
			{
				if (info->found == 0)
				{
					info->y = y;
					info->x = x;
				}
				info->found++;
				map[y][x] = '.';
			}
			x++;
			if (map[y][x] == '\0')
				y++;
			if (x == info->size - 1 && y == info->size - 1)
			{
				if (map[y][x] == tetro->letter - 1)
					map[y][x] = '.';
				return ;
			}
		}
	}
}
