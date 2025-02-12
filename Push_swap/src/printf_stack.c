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
