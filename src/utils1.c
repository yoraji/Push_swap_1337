/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:31:50 by marvin            #+#    #+#             */
/*   Updated: 2025/02/12 03:31:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	strcpy(dup, s);
	return (dup);
}

void	free_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
}

void	exit_error(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || *stack_a)
		free_stack_1(stack_a);
	if (!stack_b || *stack_b)
		free_stack_1(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
