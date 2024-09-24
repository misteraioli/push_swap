/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:06:03 by niperez           #+#    #+#             */
/*   Updated: 2024/09/24 16:18:43 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	ft_printf("Éléments de la liste: ");
	while (temp != NULL)
	{
		ft_printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	ft_printf("\n");
}

void	sort(int a, t_list **lists, int size_tab, char **instruc)
{
	int		**tableau;
	int		ter_size[7];

	if ((a == 1 && (size_tab == 1 || is_sort(lists[0])))
		|| (a > 1 && size_tab == 0))
		return ;
	if ((a % 2 == 0) && ft_lstsize(lists[0]) == size_tab)
		return (sort(a - 1, lists, size_tab, instruc));
	fill_good_tab(a, lists, size_tab, &tableau);
	tercile(tableau, ter_size, size_tab);
	while (size_tab--)
		move_lists(a, lists, ter_size, instruc);
	sort_again(a, lists, ter_size, instruc);
}

int	main(int argc, char **argv)
{
	t_list	*lists[2];
	char	*instruc;

	lists[0] = NULL;
	lists[1] = NULL;
	if ((argc == 1)
		|| (argc == 2 && parsing(argv, &lists[0]))
		|| (argc > 2 && fill_list(argc, argv, &lists[0])))
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
