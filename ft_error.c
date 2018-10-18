/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:19:32 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:44:32 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit target_file\n", 1);
		exit(1);
	}
}

void	ft_open_failed(void)
{
	ft_putstr_fd("Error : Can't open file\n", 1);
	exit(1);
}
