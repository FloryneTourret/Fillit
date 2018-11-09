/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <nzenzela@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 08:50:45 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[21 + 1];
	int		ret;
	int		id;
	
	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while ((ret = read(fd, buf, 21)))
	{
		id++;
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_putchar('\n');
		check_tetro(buf, id) == 0 ? stock_tetro(buf) : ft_error();
	}
	if (close(fd) == -1)
		ft_error();
	return (0);
}

void	stock_tetro(char *str)
{
	str = NULL;
	ft_putstr("le tetros est valide !\n");
}
