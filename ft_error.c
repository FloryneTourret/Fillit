/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:19:32 by naplouvi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 16:31:45 by naplouvi    ###    #+. /#+    ###.fr     */
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

void	ft_error(void)
{
	ft_putstr_fd("error\n", 1);
	exit(1);
}
