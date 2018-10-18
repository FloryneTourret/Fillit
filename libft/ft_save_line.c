/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 12:51:09 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:54:30 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_save_line(char *files)
{
	if (ft_strchr(files, '\n'))
	{
		ft_strcpy(files, ft_strchr(files, '\n') + 1);
		return (files);
	}
	if (ft_linelen(files) > 0)
	{
		ft_strcpy(files, ft_strchr(files, '\0'));
		return (files);
	}
	return (NULL);
}
