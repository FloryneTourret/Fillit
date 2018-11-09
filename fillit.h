/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 14:56:41 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetro
{
	char			*content;
	int				id;
	struct s_tetro	*previous;
	struct s_tetro	*next;
}					t_tetro;

void				ft_usage(int argc);
void				ft_error(void);
int					check_tetro(char *buf, int id);
int					ft_countchar(char *str, char c);
int					stock_tetro(char *str, char *tetro);
int					tetro_is_valid(char *buf, int i, int tetro, char id);
void				resolve_tetro(char **tetros, int id);

#endif
