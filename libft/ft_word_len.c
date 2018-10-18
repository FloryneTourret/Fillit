/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_word_len.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:46:31 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:46:43 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_len(char const *str, int index, char c)
{
	int	i;

	i = 0;
	while (str[index] != c && str[index] != '\0')
	{
		index++;
		i++;
	}
	return (i);
}
