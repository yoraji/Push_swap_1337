/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:33:25 by marvin            #+#    #+#             */
/*   Updated: 2025/02/11 15:58:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cheack_arg(char *arg)
{
	int	i;

	i = 0;
	if (is_sign(arg[i]))
		i++;
	while (arg[i] && is_digit(arg[i]))
		i++;
	if (arg[i] && !is_digit(arg[i]))
		return (0);
	return (1);
}

static int	cheack_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

int	is_empty_av(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (av[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicates(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = 0;
		while (av[++j])
			if (j != i && !compare_num(av[i], av[j]))
				return (1);
	}
	return (0);
}

int	cheack_input(char **av)
{
	int	i;
	int	zero;

	i = -1;
	zero = 0;
	if (is_duplicates(av))
		return (free_tab(av), exit_error(NULL, NULL), 0);
	while (av[++i])
	{
		if (!cheack_arg(av[i]))
			return (free_tab(av), exit_error(NULL, NULL), 0);
		zero += cheack_zero(av[i]);
	}
	if (zero > 1)
		return (free_tab(av), exit_error(NULL, NULL), 0);
	return (1);
}
