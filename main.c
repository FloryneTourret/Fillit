/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:33:05 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[21 + 1];
	int		id;
	char	*tetros[26 + 1];
	int		ret;

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
	// ft_putsstr(resolve_tetro(tetros, id - 1), id);
	resolve_tetro(tetros, id - 1);
	if (close(fd) == -1)
		ft_error();
	return (0);
}
