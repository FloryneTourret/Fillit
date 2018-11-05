/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:35:47 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[21 + 1];
	int		ret;

	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while (ret = read(fd, buf, 21))
	{
		buf[ret] = '\0';
		check_tetro(buf) == 0 ? stock_tetro(buf) : ft_error();
	}
	if (close(fd) == -1)
		ft_error();
	return (0);
}

