/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_first_word.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:13:59 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 13:14:36 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getfirstword(const char *str)
{
	int		i;
	char	*res;
	int		len;
	int		pos;

	i = 0;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	pos = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		len++;
		i++;
	}
	res = ft_strsub(str, pos, len);
	return (res);
}
