/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:46:15 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:46:15 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scan(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i + 1);
}

static int	ft_revscan(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = ft_scan(s1, set);
	end = ft_revscan(s1, set);
	if (end - start + 1 < 0)
		return (ft_calloc(1, sizeof(char)));
	p = ft_substr(s1, start - 1, end - start + 1);
	if (!p)
		return (NULL);
	return (p);
}
