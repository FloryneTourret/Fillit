/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:06:05 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:46:23 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s != NULL)
	{
		if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			dest[i] = s[start];
			i++;
			start++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
