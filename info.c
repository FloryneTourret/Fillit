/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fcts.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 15:32:41 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 15:33:42 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	increase_line(t_info *info)
{
	info->y++;
	info->x = 0;
}

void	initialize(t_info *info, int id)
{
	info->x = 0;
	info->y = 0;
	info->size = find_size(id);
	info->id = -1;
	info->found = 0;
	info->nb_tetros = id;
}
