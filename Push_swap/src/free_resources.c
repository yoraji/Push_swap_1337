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

int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

char*	str_ndup(char *str, unsigned int n)
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

int is_empty(char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
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

static char*	word_dup(char *str, int start, int end)
{
	char*	word;
	int	i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char**	ft_split(char *str, char sep, int *size)
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

int abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

char**	join(int argc, char **argv, int *size)
{
	char*	join_str;
	char**	tab;
	int	i;

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
			char *temp_space = ft_strjoin(join_str, " ");
			free(join_str);
			join_str = temp_space;
			if (!join_str)
				exit_error(NULL, NULL);
		}
		char *temp = ft_strjoin(join_str, argv[i]);
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

t_list*	filling_stack(int size, char **ptr)
{
	t_list*	stack;
	t_list*	new;
	int		i;
	stack = NULL;
	i = 0;
	while (i < size)
	{
		new = new_list(ft_atoi(ptr[i]));
		if (!new)
			exit_error(&stack, NULL);
		ft_stack_add_back(&stack, new);
		i++;
	}
	return (stack);
}

void	put_index(t_list *stack, int size)
{
	int*	arr;
	t_list* tmp;
	arr = convert_stack_to_array(stack);
	bubble_sort(arr, size);
	tmp = stack;
	while (tmp)
	{
		tmp->index = get_index(arr, size, tmp->value);
		tmp = tmp->next;
	}
}
