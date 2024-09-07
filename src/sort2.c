/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:30:47 by niperez           #+#    #+#             */
/*   Updated: 2024/08/27 23:08:44 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_tab(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (*tab[i] > *tab[j])
				ft_swap(tab[i], tab[j]);
			j++;
		}
		i++;
	}
}

static void	free_tab(int **tab, int size)
{
	while (size > 0)
		free(tab[--size]);
	free(tab);
}

void	quartile(int **tab, int *q3_size, int size_tab)
{
	sort_tab(tab, size_tab);
	q3_size[2] = size_tab / 3 + 1;
	q3_size[3] = size_tab / 3;
	if (size_tab % 3 > 1)
		q3_size[3] += 1;
	q3_size[0] = *tab[q3_size[2] - 1];
	q3_size[1] = *tab[q3_size[2] + q3_size[3] - 1];
	if (size_tab % 3 < 1)
		q3_size[2] -= 1;
	q3_size[4] = size_tab - q3_size[2] - q3_size[3];
	free_tab(tab, size_tab);
}

void	fill_tab(t_list *lst, int ***tab, int size_tab)
{
	int		i;

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
		*(*tab)[i++] = *(int *)(lst)->content;
		(lst) = (lst)->next;
	}
}
