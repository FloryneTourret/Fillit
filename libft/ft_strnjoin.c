/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 12:49:54 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:54:15 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t len)
{
	char	*str;
	size_t	n;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	n = ft_strlen(s1) + len + 1;
	str = ft_strnew(n);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	len++;
	while (s2[j] != '\0' && --len > 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
