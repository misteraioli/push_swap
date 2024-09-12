/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:30:47 by niperez           #+#    #+#             */
/*   Updated: 2024/09/11 02:40:03 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_lists(int a, t_list **lists, int *ter_size, char **instruc)
{
	int		value;
	char	*name[2];

	name[0] = "a\n";
	name[1] = "a\n";
	if (a <= 2)
		name[1] = "b\n";
	else
		name[0] = "b\n";
	if (a == 2 || a == 4)
		ft_rr(lists, name, instruc);
	value = *(int *)(lists[0])->content;
	if ((a == 1 && value >= ter_size[2]) || (a == 3 && value < ter_size[1]))
		ft_r(0, lists, name, instruc);
	else if ((a <= 2 && value < ter_size[2]) || (a > 2 && value >= ter_size[1]))
	{
		ft_p(lists, name, instruc);
		if ((a <= 2 && value < ter_size[1]) || (a > 2 && value < ter_size[2]))
			ft_r(1, lists, name, instruc);
	}
}

static t_list	**invert(t_list **lists)
{
	t_list	*temp;

	temp = lists[0];
	lists[0] = lists[1];
	lists[1] = temp;
	return (lists);
}

void	sort_again(int a, t_list **lists, int *ter_size, char **instruc)
{
	if (a <= 2)
	{
		if (a == 1)
			sort(2, lists, ter_size[4], instruc);
		else if (a == 2)
			sort(1, lists, ter_size[4], instruc);
		sort(3, invert(lists), ter_size[5], instruc);
		sort(4, lists, ter_size[6], instruc);
		invert(lists);
	}
	else
	{
		sort(1, invert(lists), ter_size[4], instruc);
		sort(2, lists, ter_size[5], instruc);
		if (a == 3)
			sort(4, invert(lists), ter_size[6], instruc);
		else if (a == 4)
			sort(3, invert(lists), ter_size[6], instruc);
	}
}

int	is_sort(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (1);
	while (lst->next != NULL)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
