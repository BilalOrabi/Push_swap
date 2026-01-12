/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:46:19 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:46:19 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			plen;
	char			*p;

	if (!s)
		return (0);
	plen = 0;
	while (start < ft_strlen(s) && (plen < len && s[start + plen]))
		plen++;
	p = malloc(sizeof(char) * (plen + 1));
	if (!p)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return ((char *)p);
}
