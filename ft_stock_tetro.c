/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stock_tetro.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 14:11:44 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 15:14:47 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	stock_tetro(char *str, char *tetro)
{
	int	i;

	if (!(tetro = malloc(sizeof(char) * 21)))
		return (1);
	i = 0;
	while (i < 20)
	{
		tetro[i] = str[i];
		i++;
	}
	tetro[i] = '\0';
	return (0);
}
