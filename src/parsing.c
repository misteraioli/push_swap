/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niperez <niperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:36:21 by niperez           #+#    #+#             */
/*   Updated: 2024/09/24 17:35:26 by niperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	if (!(ft_isdigit(*str) || *str == '+' || *str == '-'))
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

static int	is_int(const char *str)
{
	if (*str == '-')
	{
		if (ft_strlen(str) < 11)
			return (1);
		else if (ft_strlen(str) > 11)
			return (0);
		return (ft_strncmp("-2147483648", str, ft_strlen(str)) >= 0);
	}
	else
	{
		if (*str == '+')
			str++;
		if (ft_strlen(str) < 10)
			return (1);
		else if (ft_strlen(str) > 10)
			return (0);
		return (ft_strncmp("2147483647", str, ft_strlen(str)) >= 0);
	}
}

static int	check_double(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (*((int *)current->content) == *((int *)next->content))
				return (ft_lstclear(lst, free), ft_putstr_fd("Error\n", 2), 1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}

int	fill_list(int argc, char **argv, t_list **lst)
{
	int		*value;
	t_list	*new_node;

	while (--argc)
	{
		if (!(is_number(argv[argc])) || !(is_int(argv[argc])))
			return (ft_lstclear(lst, free), ft_putstr_fd("Error\n", 2), 1);
		value = malloc(sizeof(int));
		if (value == NULL)
			return (ft_lstclear(lst, free), 1);
		*value = ft_atoi(argv[argc]);
		new_node = ft_lstnew(value);
		if (new_node == NULL)
			return (free(value), ft_lstclear(lst, free), 1);
		ft_lstadd_front(lst, new_node);
	}
	if (check_double(lst))
		return (1);
	return (0);
}

int	parsing(char **argv, t_list	**list)
{
	char	**argv_new;
	int		argc;
	char	*name_space;
	char	*argv_str;
	int		error;

	name_space = ft_strjoin(argv[0], " ");
	argv_str = ft_strjoin(name_space, argv[1]);
	argv_new = ft_split(argv_str, ' ');
	free(name_space);
	free(argv_str);
	argc = 1;
	while (argv_new[argc])
		argc++;
	error = fill_list(argc, argv_new, list);
	argc++;
	while (argc)
		free(argv_new[--argc]);
	free(argv_new);
	return (error);
}
