/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 14:46:07 by fleonard     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:53:33 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include <unistd.h>
# include <stdlib.h>

unsigned int	ft_linelen(char *files);
char			*ft_strnjoin(char *s1, char *s2, size_t len);
char			*ft_save_line(char *files);
int				get_next_line(int const fd, char **line);

#endif
