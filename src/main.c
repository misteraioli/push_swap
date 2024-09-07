/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:06:03 by niperez           #+#    #+#             */
/*   Updated: 2024/08/29 00:43:08 by niperez          ###   ########.fr       */
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

int	replace_word(char *str, const char *old_word, const char *new_word)
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

int	main(int argc, char **argv)
{
	t_list	*lists[2];
	char	*instruc;

	lists[0] = NULL;
	lists[1] = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2 && parsing(argv, &lists[0]))
		return (1);
	else if (argc > 2 && fill_list(argc, argv, &lists[0]))
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
