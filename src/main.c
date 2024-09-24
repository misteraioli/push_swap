/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:06:03 by niperez           #+#    #+#             */
/*   Updated: 2024/09/24 17:57:29 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int cas, t_list **lists, int size, char **instruc)
{
	int	**tableau;
	int	tercile[7];

	if ((cas == 1 && is_sort(lists[0], size)) || (cas > 1 && size == 0))
		return ;
	if ((cas % 2 == 0) && ft_lstsize(lists[0]) == size)
		return (sort(cas - 1, lists, size, instruc));
	fill_good_tab(cas, lists, size, &tableau);
	tercil_calc(tableau, tercile, size);
	while (size--)
		move_lists(cas, lists, tercile, instruc);
	sort_again(cas, lists, tercile, instruc);
}

int	main(int argc, char **argv)
{
	t_list	*lists[2];
	char	*instruc;

	lists[0] = NULL;
	lists[1] = NULL;
	if ((argc == 1)
		|| (argc > 2 && fill_list(argc, argv, &lists[0]))
		|| (argc == 2 && parsing(argv, &lists[0])))
		return (1);
	instruc = malloc(sizeof(char));
	*instruc = '\0';
	sort(1, lists, ft_lstsize(lists[0]), &instruc);
	ft_lstclear(&lists[0], free);
	ft_lstclear(&lists[1], free);
	opti_instruc(instruc);
	ft_putstr_fd(instruc, 1);
	free(instruc);
	return (0);
}
