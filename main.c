/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 12:34:07 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			id;
	char		*tetros[26 + 1];
	t_info		*info;

	id = 0;
	ft_usage(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	id = read_tetros(fd, id, tetros);
	if ((info = malloc(sizeof(t_info))) == NULL || close(fd) == -1)
		ft_error();
	info->x = 0;
	info->y = 0;
	info->size = 2;
	info->id = -1;
	info->found = 0;
	info->nb_tetros = id;
	ft_putsstr(resolve_tetro(tetros, info), info->size);
	return (0);
}
