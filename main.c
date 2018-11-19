/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:01:47 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 18:44:26 by ftourret    ###    #+. /#+    ###.fr     */
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
	char		**map;

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
	if ((map = (char **)malloc(sizeof(char *) * info->size + 1)) == NULL)
		ft_error();
	ft_putsstr((map = resolve_tetro(tetros, info, map)), info->size);
	free_content(map);
	while (--id >= 0)
		tetros[id] = NULL;
	return (0);
}
