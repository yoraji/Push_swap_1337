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

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

char	*ft_strdup(const char *s)
{
	char*	dup;
	size_t len;

	len = strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return NULL;
	strcpy(dup, s);
	return (dup);
}

int is_empty(char *av)
{
	if (!av || !*av)
		return (1);
	while (*av)
	{
		if (*av != ' ')
			return (0);
		av++;
	}
	return (1);
}