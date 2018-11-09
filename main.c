/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 15:49:32 by naplouvi    ###    #+. /#+    ###.fr     */
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
	char	*tetros[26];

	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (check_tetro(buf, id) == 0)
			tetros[id] = ft_strsub(buf, 0, 21);
		else
			ft_error();
		id++;
	}
	resolve_tetro(tetros, id);
	if (close(fd) == -1)
		ft_error();
	return (0);
}

void	resolve_tetro(char **tetros, int id)
{
	int	i;

	i = 0;
	while (i < id)
	{
		ft_putstr(tetros[i]);
		ft_putchar('\n');
		i++;
	}
}
