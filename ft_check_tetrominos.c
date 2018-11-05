/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_tetrominos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:51:06 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:51:00 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetro(char *buf)
{
	int			i;
	static int	id;
	int			count_full;
	int			count_empty;

	i = 0;
	count_full = 0;
	count_empty = 0;
	id = 1;
	if (buf[20] != '\n' || buf[20] != '\0' || id > 26)
		return (1);
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (1);
	while (buf[i] && (buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
	{
		i++;
	}
	return (1);
}

int	ft_countchar(char *str, char c)
{
	int	i;
	int	occurence;

	i = 0;
	occurence = 0;
	while (str[i])
	{
		if (str[i] == c)
			occurence++;
		i++;
	}
	return (occurence);
}
