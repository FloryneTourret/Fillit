/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 18:49:13 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:45:22 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(dst = ft_memalloc(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			dst[i] = s2[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
