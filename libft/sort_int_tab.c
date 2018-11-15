/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_int_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: naplouvi <naplouvi@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:52:55 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 19:53:10 by naplouvi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;
	unsigned int	j;

	j = 0;
	tmp = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
