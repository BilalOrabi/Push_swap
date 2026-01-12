/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:45:24 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:45:24 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(src);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, len + 1);
	return (copy);
}
