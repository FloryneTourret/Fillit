/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:19:32 by naplouvi     #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/10/18 16:55:45 by naplouvi    ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/10/18 16:44:32 by ftourret    ###    #+. /#+    ###.fr     */
>>>>>>> a1b5d530b019aaa88ad0fcdaa8db87b84d01ffd4
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
<<<<<<< HEAD
	exit(1);
}

void	ft_unvalid_file(void)
{
	ft_putstr_fd("Error : Unvalid file\n", 1);
=======
>>>>>>> a1b5d530b019aaa88ad0fcdaa8db87b84d01ffd4
	exit(1);
}
