/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 14:45:48 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:54:05 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int						get_next_line(int const fd, char **line)
{
	char			*str;
	char			buf[BUFF_SIZE + 1];
	static char		*files[256];
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(files[fd]) && (files[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(files[fd], '\n')) &&
	(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = files[fd];
		files[fd] = ft_strnjoin(str, buf, ret);
		free(str);
	}
	*line = ft_strsub(files[fd], 0, ft_linelen(files[fd]));
	if (ft_save_line(files[fd]) == NULL)
		return (0);
	return (1);
}
