/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:14:32 by niperez           #+#    #+#             */
/*   Updated: 2024/09/10 22:20:20 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	replace_word(char *str, const char *old_word, const char *new_word)
{
	char	*pos;
	int		old_word_len;
	int		new_word_len;
	int		i;

	i = 0;
	old_word_len = ft_strlen(old_word);
	new_word_len = ft_strlen(new_word);
	pos = ft_strnstr(str, old_word, ft_strlen(str));
	while (pos)
	{
		if (old_word_len - new_word_len != 0)
			ft_memmove(pos + new_word_len, pos + old_word_len,
				ft_strlen(pos + old_word_len) + 1);
		ft_memcpy(pos, new_word, new_word_len);
		pos = ft_strnstr(str, old_word, ft_strlen(str));
		i = 1;
	}
	return (i);
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
