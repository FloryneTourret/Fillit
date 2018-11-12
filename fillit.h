/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:00:30 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 17:18:21 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>


void				ft_usage(int argc);
void				ft_error(void);
int					ft_countchar(char *str, char c);
void				ft_putsstr(char **str, int nb);
int					check_tetro(char *buf, int id);
int					tetro_is_valid(char *buf, int i, int tetro, char id);
char				**resolve_tetro(char **tetros, int nbr_tetros);
char				**create_map(int size);
int					solver(char **map, char **tetros, int id, int nbr_tetros);
int					place_tetro(char *tetros, char **map, int x, int y);
void				free_content(char **content);

#endif
