/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbeul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:32 by niperez           #+#    #+#             */
/*   Updated: 2024/08/28 23:42:09 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	localisation(int a, char **name)
{
	if (a <= 2)
	{
		name[0] = "a\n";
		name[1] = "b\n";
	}
	else
	{
		name[0] = "b\n";
		name[1] = "a\n";
	}
}

void	move_lists(int a, t_list **lists, int *q3_size, char **instruc)
{
	int		value;
	char	*name[2];

	localisation(a, name);
	if (a == 2 || a == 4)
		ft_rr(lists, name, instruc);
	value = *(int *)(lists[0])->content;
	if ((a == 1 && value >= q3_size[1]) || (a == 3 && value < q3_size[0]))
		ft_r(0, lists, name, instruc);
	else if (((a == 1 || a == 2) && value < q3_size[1])
		|| ((a == 3 || a == 4) && value >= q3_size[0]))
	{
		ft_p(lists, name, instruc);
		if (((a == 1 || a == 2) && value < q3_size[0])
			|| ((a == 3 || a == 4) && (value < q3_size[1])))
			ft_r(1, lists, name, instruc);
	}
}

static void	opti1(int *i, char *instruc)
{
	*i += replace_word(instruc, "rra\nra\n", "");
	*i += replace_word(instruc, "rrb\nrb\n", "");
	*i += replace_word(instruc, "\nra\nrra\n", "\n");
	*i += replace_word(instruc, "\nrb\nrrb\n", "\n");
	*i += replace_word(instruc, "pa\npb\n", "");
	*i += replace_word(instruc, "pb\npa\n", "");
	*i += replace_word(instruc, "sa\nsa\n", "");
	*i += replace_word(instruc, "sb\nsb\n", "");
	*i += replace_word(instruc, "ss\nss\n", "");
	*i += replace_word(instruc, "\nrb\nra\n", "\nra\nrb\n");
	*i += replace_word(instruc, "rrb\nra\n", "ra\nrrb\n");
	*i += replace_word(instruc, "sb\nra\n", "ra\nsb\n");
	*i += replace_word(instruc, "\nrb\nrra\n", "\nrra\nrb\n");
	*i += replace_word(instruc, "rrb\nrra\n", "rra\nrrb\n");
	*i += replace_word(instruc, "sb\nrra\n", "rra\nsb\n");
	*i += replace_word(instruc, "\nrb\nsa\n", "\nsa\nrb\n");
	*i += replace_word(instruc, "rrb\nsa\n", "sa\nrrb\n");
	*i += replace_word(instruc, "sb\nsa\n", "sa\nsb\n");
}

static void	opti2(int *i, char *instruc)
{
	*i += replace_word(instruc, "ss\nsa\n", "sa\nss\n");
	*i += replace_word(instruc, "ss\nsb\n", "sb\nss\n");
	*i += replace_word(instruc, "\nrr\nra\n", "\nra\nrr\n");
	*i += replace_word(instruc, "\nrr\nrb\n", "\nrb\nrr\n");
	*i += replace_word(instruc, "rrr\nrra\n", "rra\nrrr\n");
	*i += replace_word(instruc, "rrr\nrrb\n", "rrb\nrrr\n");
	*i += replace_word(instruc, "\nra\nrb\n", "\nrr\n");
	*i += replace_word(instruc, "\nrb\nra\n", "\nrr\n");
	*i += replace_word(instruc, "rra\nrrb\n", "rrr\n");
	*i += replace_word(instruc, "rrb\nrra\n", "rrr\n");
	*i += replace_word(instruc, "\nrr\nrrr\n", "\n");
	*i += replace_word(instruc, "\nrrr\nrr\n", "\n");
	*i += replace_word(instruc, "\nsa\nsb\n", "\nss\n");
	*i += replace_word(instruc, "\nsb\nsa\n", "\nss\n");
}

void	opti_instruc(char *instruc)
{
	int	i;

	i = 1;
	while (i)
	{
		i = 0;
		opti1(&i, instruc);
		opti2(&i, instruc);
		i += replace_word(instruc, "pb\npb\nsb\npa\npa\n", "sa\n");
		i += replace_word(instruc, "pa\npa\nsa\npb\npb\n", "sb\n");
		i += replace_word(instruc, "pb\nsb\npa\npa\n", "pa\nsa\n");
		i += replace_word(instruc, "pa\nsa\npb\npb\n", "pb\nsb\n");
		i += replace_word(instruc, "pb\npb\nsb\npa\n", "sa\npb\n");
		i += replace_word(instruc, "pa\npa\nsa\npb\n", "sb\npa\n");
		i += replace_word(instruc, "\nra\npa\nrra\n", "\npa\nsa\n");
		i += replace_word(instruc, "\nrb\npb\nrrb\n", "\npb\nsb\n");
		i += replace_word(instruc, "sa\npb\nra\npa\nrra\n", "");
		i += replace_word(instruc, "sb\npa\nrb\npb\nrrb\n", "");
	}
}
