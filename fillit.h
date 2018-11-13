/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:36:22 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetro
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				x3;
	int				y3;
	int				x4;
	int				y4;
}					t_tetro;

void				ft_usage(int argc);
void				ft_error(void);
int					ft_countchar(char *str, char c);
void				ft_putsstr(char **str, int nb);
int					check_tetro(char *buf, int id);
int					tetro_is_valid(char *buf, int i, int tetro, char id);
char				**resolve_tetro(char **tetros, int nbr_tetros);
char				**create_map(int size);
int					resolve(char **map, char **tetros, int size, int nb_tetros);
t_tetro				*coord(char **tetros, int id, int x, int y);
int					solver(char **map, char **tetros, int id, int size);
void				stock_tetro(t_tetro *tetro, int x, int y, int found);
int					place_tetro(char *tetros, char **map, int x, int y);
void				free_content(char **content);

#endif
