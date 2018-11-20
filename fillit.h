/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 13:09:14 by ftourret    ###    #+. /#+    ###.fr     */
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

typedef struct		s_info
{
	int				x;
	int				y;
	int				size;
	int				id;
	int				found;
	int				nb_tetros;
}					t_info;

void				ft_usage(int argc);
void				ft_error(void);
void				ft_putsstr(char **str, int nb);
int					ft_countchar(char *str, char c);
int					check_tetro(char *buf, int id);
int					tetro_is_valid(char *buf, int i, int tetro, char id);
char				**resolve_tetro(char **tetros, t_info *info, char **map);
int					resolve(char **map, char **tetros, t_info *info);
int					check_free(char **map, char **tetros, t_tetro *tetro, t_info *info);
int					is_free(char **map, t_tetro *tetro, int x, int y);
int					remove_tetro(char **map, t_tetro *tetro, t_info *info);
int					backtracking(char **map, char **tetros, t_tetro *tetro, t_info *info);
int					find_size(int id);
char				**create_map(int size, char **map);
void				free_content(char **content);
t_tetro				*coord(t_tetro *tetro, char **tetros, int id);
void				stock_tetro(t_tetro *tetro, int x, int y, int found);
int					min(int val1, int val2, int val3, int val4);
void				serialize_tetro(t_tetro *tetro);
int					read_tetros(int fd, int id, char **tetros);

#endif
