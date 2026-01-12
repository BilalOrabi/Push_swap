/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:45:34 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/09 01:32:22 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t				dst_length;
	size_t				remaining;
	char				*dst;
	const char			*src_start;

	dst = dest;
	src_start = src;
	remaining = size;
	while (remaining-- != 0 && *dst != '\0')
		dst++;
	dst_length = dst - dest;
	remaining = size - dst_length;
	if (remaining == 0)
		return (dst_length + ft_strlen(src));
	while (*src != '\0')
	{
		if (remaining > 1)
		{
			*dst++ = *src;
			remaining--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + (src - src_start));
}
