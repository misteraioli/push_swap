/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:30:47 by niperez           #+#    #+#             */
/*   Updated: 2024/09/24 17:57:33 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_lists(int cas, t_list **lists, int *tercil, char **instruc)
{
	int		value;
	char	*name[2];

	if (cas <= 2)
	{
		name[0] = "a\n";
		name[1] = "b\n";
	}
	else
	{
		name[0] = "b\n";
		name[1] = "a\n";
	}
	if (cas % 2 == 0)
		ft_rr(lists, name, instruc);
	value = *(int *)(lists[0])->content;
	if ((cas == 1 && value >= tercil[2]) || (cas == 3 && value < tercil[1]))
		ft_r(0, lists, name, instruc);
	else if ((cas <= 2 && value < tercil[2]) || (cas > 2 && value >= tercil[1]))
	{
		ft_p(lists, name, instruc);
		if ((cas <= 2 && value < tercil[1]) || (cas > 2 && value < tercil[2]))
			ft_r(1, lists, name, instruc);
	}
}

static void	invert(t_list **lists)
{
	t_list	*temp;

	temp = lists[0];
	lists[0] = lists[1];
	lists[1] = temp;
}

void	sort_again(int cas, t_list **lists, int *tercil, char **instruc)
{
	int	s;

	s = 3;
	if (cas <= 2)
	{
		if (cas == 1)
			sort(2, lists, tercil[s + 3], instruc);
		else if (cas == 2)
			sort(1, lists, tercil[s + 3], instruc);
		invert(lists);
		sort(3, lists, tercil[s + 2], instruc);
		sort(4, lists, tercil[s + 1], instruc);
		invert(lists);
	}
	else
	{
		invert(lists);
		sort(1, lists, tercil[s + 3], instruc);
		sort(2, lists, tercil[s + 2], instruc);
		invert(lists);
		if (cas == 3)
			sort(4, lists, tercil[s + 1], instruc);
		else if (cas == 4)
			sort(3, lists, tercil[s + 1], instruc);
	}
}

int	is_sort(t_list *lst, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}
