/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azidouh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:41:39 by azidouh           #+#    #+#             */
/*   Updated: 2025/10/19 18:41:41 by azidouh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*free_split(char **res, int j)
{
	while (j >= 0)
		free(res[j--]);
	free(res);
	return (NULL);
}

static char	**split_helper(char **res, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			res[j] = copy_word(s, start, i);
			if (!res[j++])
				return (free_split(res, j - 2));
		}
	}
	res[j] = NULL;
	return (res);
}


char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 2));
	if (!res)
		return (NULL);
	res[0] = malloc(1);
	if (!res[0])
		return (free(res), NULL);
	res[0][0] = '\0';
	return (split_helper(res, s, c));
}
