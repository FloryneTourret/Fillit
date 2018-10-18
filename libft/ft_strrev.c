/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:44:18 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:46:11 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	k;

	i = 0;
	j = 0;
	while (str[i + 1] != '\0')
	{
		i++;
	}
	while (j < i)
	{
		k = str[j];
		str[j] = str[i];
		str[i] = k;
		j++;
		i--;
	}
	return (str);
}
