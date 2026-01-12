/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:45:53 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:45:53 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	copylen;

	srclen = ft_strlen(src);
	if (destsize)
	{
		if (srclen < destsize -1)
			copylen = srclen;
		else
			copylen = destsize - 1;
		ft_memcpy(dest, src, copylen);
		dest[copylen] = '\0';
	}
	return (srclen);
}
