/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:42:26 by niperez           #+#    #+#             */
/*   Updated: 2024/09/07 20:40:53 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instruc(const char *str, int i, char **name, char **instruc)
{
	char	*temp;
	char	*temp2;

	temp2 = ft_strjoin(str, name[i]);
	temp = ft_strjoin(*instruc, temp2);
	free(temp2);
	free(*instruc);
	*instruc = temp;
}

void	ft_r(int i, t_list **lists, char **name, char **instruc)
{
	if (ft_lstsize(lists[i]) > 2)
	{
		lst_rotate(&lists[i]);
		ft_instruc("r", i, name, instruc);
	}
	else if (ft_lstsize(lists[i]) == 2)
	{
		lst_swap(&lists[i]);
		ft_instruc("s", i, name, instruc);
	}
}

void	ft_rr(t_list **lists, char **name, char **instruc)
{
	if (ft_lstsize(lists[0]) > 2)
	{
		lst_reverse_rotate(&lists[0]);
		ft_instruc("rr", 0, name, instruc);
	}
	else if (ft_lstsize(lists[0]) == 2)
	{
		lst_swap(&lists[0]);
		ft_instruc("s", 0, name, instruc);
	}
}

void	ft_p(t_list **lists, char **name, char **instruc)
{
	lst_push(&lists[1], &lists[0]);
	ft_instruc("p", 1, name, instruc);
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
