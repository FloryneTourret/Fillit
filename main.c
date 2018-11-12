/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 17:23:46 by naplouvi    ###    #+. /#+    ###.fr     */
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

	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while (read(fd, buf, 21))
	{
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
	ft_putsstr(resolve_tetro(tetros, id - 1), id);
	if (close(fd) == -1)
		ft_error();
	return (0);
}
