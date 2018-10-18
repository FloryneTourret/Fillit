/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_tetrominos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:51:06 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 17:02:46 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_tetrominos(char **tetro)
{
	int	i;
	int	j;

	i = 0;
	while (tetro[i])
	{
		j = 0;
		if (ft_linelen(tetro[i]) != 4)
			ft_unvalid_file();
		while (tetro[i][j])
		{
			if (tetro[i][j] != '.' || tetro[i][j] != '#')
				ft_unvalid_file();
			j++;
		}
		i++;
	}
	return (0);
}
