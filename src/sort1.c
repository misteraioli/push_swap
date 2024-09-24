/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:47:51 by niperez           #+#    #+#             */
/*   Updated: 2024/09/24 17:39:08 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tab(int **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
}

static void	fill_tab(t_list *lst, int ***tab, int size_tab)
{
	int	i;

	*tab = malloc(sizeof(int *) * size_tab);
	if (*tab == NULL)
	{
		ft_lstclear(&lst, free);
		exit(1);
	}
	i = 0;
	while (i < size_tab)
	{
		(*tab)[i] = malloc(sizeof(int));
		if ((*tab)[i] == NULL)
		{
			ft_lstclear(&lst, free);
			free_tab(*tab, i);
			exit(1);
		}
		*(*tab)[i] = *(int *)(lst)->content;
		(lst) = (lst)->next;
		i++;
	}
}

void	fill_good_tab(int cas, t_list **lists, int size_tab, int ***tableau)
{
	int	i;

	if (cas % 2 == 0)
	{
		i = 0;
		while (i++ < size_tab)
			lst_reverse_rotate(&lists[0]);
		fill_tab(lists[0], tableau, size_tab);
		i = 0;
		while (i++ < size_tab)
			lst_rotate(&lists[0]);
	}
	else
		fill_tab(lists[0], tableau, size_tab);
}

static void	sort_tab(int **tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (*tab[i] > *tab[j])
			{
				temp = *tab[i];
				*tab[i] = *tab[j];
				*tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	tercil_calc(int **tab, int *tercil, int size_tab)
{
	int	s;

	s = 3;
	sort_tab(tab, size_tab);
	tercil[s + 1] = size_tab / 3;
	tercil[s + 2] = size_tab / 3;
	tercil[s + 3] = size_tab / 3;
	if (size_tab % 3 >= 1)
		tercil[s + 3]++;
	if (size_tab % 3 == 2)
		tercil[s + 2]++;
	tercil[0] = *tab[0];
	tercil[1] = *tab[tercil[s + 1]];
	tercil[2] = *tab[tercil[s + 1] + tercil[s + 2]];
	tercil[3] = *tab[size_tab - 1];
	free_tab(tab, size_tab);
}
