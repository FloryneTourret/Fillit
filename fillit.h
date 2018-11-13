/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:49:04 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_tetro
{
	char			letter;
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
void				ft_putsstr(char **str, int nb);
int					ft_countchar(char *str, char c);
int					check_tetro(char *buf, int id);
int					tetro_is_valid(char *buf, int i, int tetro, char id);
char				**resolve_tetro(char **tetros, int nbr_tetros);
int					resolve(char **map, char **tetros, int size, int nb_tetros);
int					is_free(char **map, t_tetro *tetro);
void				place_tetro(char **map, t_tetro *tetro, int x, int y);
char				**create_map(int size);
void				free_content(char **content);
t_tetro				*coord(t_tetro *tetro, char **tetros, int id);
void				stock_tetro(t_tetro *tetro, int x, int y, int found);
void				sort_int_tab(int *tab, unsigned int size);
int					min(int val1, int val2, int val3, int val4);
void				serialize_tetro(t_tetro *tetro);

#endif
