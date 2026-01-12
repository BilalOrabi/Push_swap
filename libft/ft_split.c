/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:45:17 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:45:17 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char delm)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != delm && (s[i + 1] == delm || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	*ft_free(int i, char **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

static char	**ft_split_helper(const char *s, char delm, int i, int j)
{
	char	**array;
	char	*temp;
	int		words;

	words = ft_words(s, delm);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (*s == delm)
			s++;
		j = 0;
		while (s[j] != delm && s[j] != '\0')
			j++;
		temp = ft_substr(s, 0, j);
		if (!temp)
			return (ft_free(i - 1, array));
		array[i] = temp;
		s = ft_strchr(s, delm);
	}
	array[words] = 0;
	return (array);
}

char	**ft_split(const char *s, char delm)
{
	if (!s)
		return (NULL);
	return (ft_split_helper(s, delm, -1, 0));
}
