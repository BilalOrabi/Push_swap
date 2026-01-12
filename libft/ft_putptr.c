/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:29:07 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:07:34 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	int			i;
	uintptr_t	address;

	i = 0;
	if (!ptr)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	address = (uintptr_t)ptr;
	i += ft_putstr("0x");
	i += ft_puthex(address, false);
	return (i);
}
