/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:42:26 by niperez           #+#    #+#             */
/*   Updated: 2024/10/23 16:33:44 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_instruc(const char *type, int i, char **name, char **instruc)
{
	char	*temp;
	char	*type_name;

	type_name = ft_strjoin(type, name[i]);
	temp = ft_strjoin(*instruc, type_name);
	free(type_name);
	free(*instruc);
	*instruc = temp;
}

void	ft_r(int i, t_list **lists, char **name, char **instruc)
{
	if (ft_lstsize(lists[i]) == 2)
	{
		lst_swap(&lists[i]);
		ft_instruc("s", i, name, instruc);
	}
	if (ft_lstsize(lists[i]) > 2)
	{
		lst_rotate(&lists[i]);
		ft_instruc("r", i, name, instruc);
	}
}

void	ft_rr(t_list **lists, char **name, char **instruc)
{
	if (ft_lstsize(lists[0]) == 2)
	{
		lst_swap(&lists[0]);
		ft_instruc("s", 0, name, instruc);
	}
	if (ft_lstsize(lists[0]) > 2)
	{
		lst_reverse_rotate(&lists[0]);
		ft_instruc("rr", 0, name, instruc);
	}
}

void	ft_p(t_list **lists, char **name, char **instruc)
{
	lst_push(&lists[1], &lists[0]);
	ft_instruc("p", 1, name, instruc);
}
