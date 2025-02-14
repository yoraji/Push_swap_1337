/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:33:50 by marvin            #+#    #+#             */
/*   Updated: 2025/02/12 04:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

char	*str_ndup(char *str, unsigned int n)
{
	unsigned int	i;
	char			*s;

	if (!str)
		return (NULL);
	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
		s[i++] = (*str)++;
	s[n] = '\0';
	return (s);
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
			in_word = 0;
		str++;
	}
	return (count);
}

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

char	**join(int argc, char **argv, int *size)
{
	char	*join_str;
	char	**tab;
	char	*temp_space;
	char	*temp;
	int		i;

	join_str = ft_strdup("");
	if (!join_str)
		exit_error(NULL, NULL);
	i = 1;
	while (i < argc)
	{
		if (is_empty(argv[i]))
			exit_error(NULL, NULL);
		if (join_str[0] != '\0')
		{
			temp_space = ft_strjoin(join_str, " ");
			free(join_str);
			join_str = temp_space;
			if (!join_str)
				exit_error(NULL, NULL);
		}
		temp = ft_strjoin(join_str, argv[i]);
		free(join_str);
		join_str = temp;
		if (!join_str)
			exit_error(NULL, NULL);
		i++;
	}
	tab = ft_split(join_str, ' ', size);
	free(join_str);
	if (!tab)
		exit_error(NULL, NULL);
	return (tab);
}

int	ft_atoi(const char *str)
{
	long int	nb;
	int			negative;
	int			i;

	nb = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * negative);
}
