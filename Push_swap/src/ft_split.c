/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:25:36 by marvin            #+#    #+#             */
/*   Updated: 2025/02/10 02:25:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static int	count_words(char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

char	**ft_split_1(char *str, char sep, int *size)
{
	char	**tab;
	int		count;
	int		i;
	int		j;
	int		start;

	if (!str || !size)
		return (NULL);
	count = count_words(str, sep);
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		start = i;
		while (str[i] && str[i] != sep)
			i++;
		if (start < i)
			tab[j++] = word_dup(str, start, i);
	}
	tab[j] = NULL;
	*size = count;
	return (tab);
}
