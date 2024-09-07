/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:26:39 by niperez           #+#    #+#             */
/*   Updated: 2024/08/27 20:14:14 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap(t_list **lst)
{
	void	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = temp;
}

void	lst_push(t_list **lst_to, t_list **lst_from)
{
	t_list	*temp;

	if (*lst_from == NULL)
		return ;
	temp = *lst_from;
	*lst_from = (*lst_from)->next;
	temp->next = NULL;
	ft_lstadd_front(lst_to, temp);
}

void	lst_rotate(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	lst_reverse_rotate(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(lst, temp->next);
	temp->next = NULL;
}
