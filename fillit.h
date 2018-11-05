/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 13:57:25 by naplouvi    ###    #+. /#+    ###.fr     */
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
int					ft_check_tetrominos(char **tetro);
int					check_tetro(char *buf);
int					ft_countchar(char *str, char c);
void				stock_tetro(char *str);

#endif
