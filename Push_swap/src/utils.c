/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:35:05 by marvin            #+#    #+#             */
/*   Updated: 2025/02/12 04:08:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_empty_const(const char *str)
{
	while (*str)
	{
		if (!is_space((unsigned char)*str))
			return 0;
		str++;
	}
	return 1;
}

void	free_stack_1(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// void	exit_error(t_list **stack_a, t_list **stack_b)
// {
// 	if (stack_a && *stack_a)
// 		free_stack(stack_a,NULL);
// 	if (stack_b && *stack_b)
// 		free_stack(NULL,stack_b);
// 	write(1,"Error\n", 6);
// 	exit(1);
// }

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

char	**fill_tab(char **av, int *size, int ac)
{
	int		i;
	char	*join;
	char	**tab;

	i = 1;
	join = ft_strdup("");
	if (av[i] == NULL || ac <= 1)
		exit(0);
	while (av[i])
	{
		if (is_empty(av[i]))
		{
			exit_error(NULL, NULL);
			printf("Hello	\n");
		}
		join = ft_strjoin(join, av[i]);
		i++;
	}
	tab = ft_split(join, ' ', size);
	free(join);
	return (tab);
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}
