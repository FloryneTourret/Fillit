/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:20:56 by ftourret     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 12:46:15 by ftourret    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strsplit_check(char const *s, char c, int i, int j)
{
	char	**tab;
	int		k;

	if ((tab = malloc(sizeof(char*) * (ft_count_words(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
		{
			k = 0;
			if ((tab[j] = (char*)malloc(sizeof(char) * ft_word_len(s, i, c)
				+ 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j][k++] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s != NULL && c != '\0')
		return (ft_strsplit_check(s, c, i, j));
	return (NULL);
}
