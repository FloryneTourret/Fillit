/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_words.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:45:26 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:42:51 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == c || str[i + 1] == '\0')
			count += 1;
		i++;
	}
	return (count);
}
