/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 19:24:14 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[21 + 1];
	int			id;
	char		*tetros[26 + 1];
	int			ret;
	t_info		*info;

	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
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
	if (id == 0)
		ft_error();
	if (tetros[id - 1][20] != '\0')
		ft_error();
	if (id == 0)
		ft_error();
	if ((info = malloc(sizeof(t_info))) == NULL)
		return (1);
	info->x = 0;
	info->y = 0;
	info->size = 2;
	info->id = -1;
	info->found = 0;
	info->nb_tetros = id;
	resolve_tetro(tetros, info);
	if (close(fd) == -1)
		ft_error();
	return (0);
}
