/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 12:00:38 by ftourret    ###    #+. /#+    ###.fr     */
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
			if (!(tetros[id] = ft_strsub(buf, 0, 20)))
				ft_error();
		}
		else
			ft_error();
		id++;
	}
	tetros[id] = NULL;
	if ((info = malloc(sizeof(t_info))) == NULL)
		return (1);
	info->x = 0;
	info->y = 0;
	info->size = 4;
	info->id = -1;
	info->found = 0;
	info->nb_tetros = id;
	resolve_tetro(tetros, info);
	// ft_putsstr(resolve_tetro(tetros, id - 1), id);
	if (close(fd) == -1)
		ft_error();
	return (0);
}
