/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_linelen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 12:48:33 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:54:17 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_linelen(char *files)
{
	unsigned int i;

	i = 0;
	while (files[i] != '\n' && files[i] != '\0')
		i++;
	return (i);
}
