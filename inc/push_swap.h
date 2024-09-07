/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:21:19 by niperez           #+#    #+#             */
/*   Updated: 2024/09/04 19:10:22 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"

int		fill_list(int argc, char **argv, t_list **lst);
int		parsing(char **argv, t_list	**list);

void	lst_swap(t_list **lst);
void	lst_push(t_list **lst_to, t_list **lst_from);
void	lst_rotate(t_list **lst);
void	lst_reverse_rotate(t_list **lst);

int		replace_word(char *str, const char *old_word, const char *new_word);
void	opti_instruc(char *instruc);

void	sort(int a, t_list **lists, int size_tab, char **instruc);
void	fill_tab(t_list *lst, int ***tab, int size_tab);
void	quartile(int **tab, int *q3_size, int size_tab);

void	move_lists(int a, t_list **lists, int *q3_size, char **instruc);
void	ft_instruc(const char *str, int i, char **name, char **instruc);
void	ft_r(int i, t_list **lists, char **name, char **instruc);
void	ft_rr(t_list **lists, char **name, char **instruc);
void	ft_p(t_list **lists, char **name, char **instruc);
int		is_sort(t_list *lst);

#endif