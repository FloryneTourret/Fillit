/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 19:49:34 by ftourret    ###    #+. /#+    ###.fr     */
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
	char	*tetros[26 + 1];

	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (check_tetro(buf, id) == 0)
			tetros[id] = ft_strsub(buf, 0, 20);
		else
			ft_error();
		id++;
	}
	tetros[id] = NULL;
	// ft_putsstr(resolve_tetro(tetros, id - 1), id);
	resolve_tetro(tetros, id - 1);
	// PENSER A GERER L'AFFICHAGE DE LA MAP RESOLUE
	if (close(fd) == -1)
		ft_error();
	return (0);
}

void	ft_putsstr(char **str, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		ft_putstr(str[i]);
		if (i != nb)
			ft_putchar('\n');
		i++;
	}
}
