/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:51:06 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 18:32:57 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetro(char *buf, int id)
{
	int			count_full;
	int			count_empty;
	int			i;

	i = 0;
	count_full = ft_countchar(buf, '#');
	count_empty = ft_countchar(buf, '.');
	if ((buf[20] == '\n' || buf[20] == '\0') && id <= 26)
	{
		if (buf[4] != '\n' || buf[9] != '\n'
		|| buf[14] != '\n' || buf[19] != '\n')
			return (1);
		if (count_full != 4 || count_empty != 12)
			return (1);
		while (buf[i] != '#')
			i++;
		if (tetro_is_valid(buf, i, 0, id + 65) == 4)
			return (0);
		else
			return (1);
	}
	return (1);
}

int	tetro_is_valid(char *buf, int i, int tetro, char letter)
{
	buf[i] = letter;
	tetro++;
	if ((i + 1 >= 0) && (i + 1 <= (int)ft_strlen(buf)) && buf[i + 1] == '#')
		tetro = tetro_is_valid(buf, i + 1, tetro, letter);
	if ((i - 1 >= 0) && (i - 1 <= (int)ft_strlen(buf)) && buf[i - 1] == '#')
		tetro = tetro_is_valid(buf, i - 1, tetro, letter);
	if ((i + 5 >= 0) && (i + 5 <= (int)ft_strlen(buf)) && buf[i + 5] == '#')
		tetro = tetro_is_valid(buf, i + 5, tetro, letter);
	if ((i - 5 >= 0) && (i - 5 <= (int)ft_strlen(buf)) && buf[i - 5] == '#')
		tetro = tetro_is_valid(buf, i - 5, tetro, letter);
	return (tetro);
}

int	ft_countchar(char *str, char c)
{
	int occurence;

	occurence = 0;
	while (*str)
		if (*str++ == c)
			occurence++;
	return (occurence);
}
