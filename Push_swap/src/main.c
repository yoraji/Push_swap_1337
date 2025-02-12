/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:07 by marvin            #+#    #+#             */
/*   Updated: 2025/02/12 04:08:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

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

void exit_error(t_list **stack_a, t_list **stack_b)
{
    if (stack_a && *stack_a)
        free_stack(stack_a, NULL);
    if (stack_b && *stack_b)
        free_stack(NULL, stack_b);
    write(1, "Error\n", 6);
    exit(1);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		swap(stack_a, "sa");
	else if (stack_size == 3)
		sort_tree(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

t_list	*fill_stack_content(int ac, char **av)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(NULL, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			ft_stack_add_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_list *stack_a, int size)
{
	t_list	*ptr;
	t_list	*highest;
	int		content;

	while (--size > 0)
	{
		ptr = stack_a;
		content = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > content && ptr->index == 0)
			{
				content = ptr->content;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**tab;

	tab = fill_tab(av, &size, ac);
	if (!is_corr_inp(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack_content(size, tab);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	assign_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	print_stack(stack_a);
	free_stack_1(&stack_a);
	free_stack_1(&stack_b);
}
