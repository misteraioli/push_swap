/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:47:51 by niperez           #+#    #+#             */
/*   Updated: 2024/09/04 19:08:10 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**invert(t_list **lists)
{
	t_list	*temp;

	temp = lists[0];
	lists[0] = lists[1];
	lists[1] = temp;
	return (lists);
}

void	reset(int a, t_list **lists)
{
	if (a < 3)
		invert(lists);
}

void	fill_good_tab(int a, t_list **lists, int size_tab, int ***tableau)
{
	int	i;

	if (a == 2 || a == 4)
	{
		i = -1;
		while (++i < size_tab)
			lst_reverse_rotate(&lists[0]);
		fill_tab(lists[0], tableau, size_tab);
		i = -1;
		while (++i < size_tab)
			lst_rotate(&lists[0]);
	}
	else
		fill_tab(lists[0], tableau, size_tab);
}

void	sort_again(int a, t_list **lists, int *q3_size, char **instruc)
{
	if (a == 1)
	{
		sort(2, lists, q3_size[2], instruc);
		sort(3, invert(lists), q3_size[3], instruc);
		sort(4, lists, q3_size[4], instruc);
	}
	else if (a == 2)
	{
		sort(1, lists, q3_size[2], instruc);
		sort(3, invert(lists), q3_size[3], instruc);
		sort(4, lists, q3_size[4], instruc);
	}
	else if (a == 3)
	{
		sort(1, invert(lists), q3_size[2], instruc);
		sort(2, lists, q3_size[3], instruc);
		sort(4, invert(lists), q3_size[4], instruc);
	}
	else if (a == 4)
	{
		sort(1, invert(lists), q3_size[2], instruc);
		sort(2, lists, q3_size[3], instruc);
		sort(3, invert(lists), q3_size[4], instruc);
	}
	reset(a, lists);
}

void	sort(int a, t_list **lists, int size_tab, char **instruc)
{
	int		**tableau;
	int		q3_size[5];

	if ((a == 1 && size_tab <= 1) || (a > 1 && size_tab < 1))
		return ;
	if ((a == 2 || a == 4) && ft_lstsize(lists[0]) == size_tab)
		return (sort(a - 1, lists, size_tab, instruc));
	if (a == 1 && is_sort(lists[0]))
		return ;
	fill_good_tab(a, lists, size_tab, &tableau);
	quartile(tableau, q3_size, size_tab);
	while (size_tab--)
		move_lists(a, lists, q3_size, instruc);
	sort_again(a, lists, q3_size, instruc);
}
