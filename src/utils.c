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
	if (!join)
		free(join);
	if (av[i] == NULL || ac <= 1)
		exit(0);
	while (av[i])
	{
		if (is_empty(av[i]))
			return (free(join), exit_error(NULL, NULL), NULL);
		join = ft_strjoin(join, av[i]);
		if (!join)
			return (free(join), exit_error(NULL, NULL), NULL);
		i++;
	}
	tab = ft_split(join, ' ', size);
	return (free(join), tab);
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
