/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:39:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 00:39:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list	*stack_a)
{
	while (stack_a)
	{
		printf("%d -> ", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("NULL\n");
}

void	exit_error__(void)
{
	write(2, "Error\n", 6);

	exit(0);
}

void	free_tab(char **tab)
{
	int	i;
	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
