/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:34:51 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/07 12:53:51 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns an array of strings obtained
// by splitting ’s’ using the character ’c’ as a delimiter.
// The array must end with a NULL pointer.
// #include "libft.h"

#include "so_long.h"

static void	*free_me(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(*arr);
	return (0);
}

static int	word_cnt(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_cpy(const char *s, int start, int delim)
{
	char	*str;
	int		index;
	size_t	len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (k <= start)
	{
		len = 0;
		while (s[j] == delim)
			j++;
		index = j;
		while (s[j] != delim && s[j] != '\0')
		{
			j++;
			len++;
		}
		if (k == start)
			str = ft_substr(s, index, len);
		k++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	j = 0;
	arr = (char **)malloc((word_cnt(s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (0);
	arr[word_cnt(s, c)] = 0;
	while (j < (word_cnt(s, c)))
	{
		arr[j] = word_cpy(s, j, c);
		if (arr[j] == 0)
			return (free_me(arr, j));
		j++;
	}
	return (arr);
}
