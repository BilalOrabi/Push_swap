/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:28:49 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:07:59 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long int n, bool uppercase)
{
	int			i;
	char		digit;
	const char	*digits;

	i = 0;
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_puthex(n / 16, uppercase);
	}
	digit = digits[n % 16];
	write(1, &digit, 1);
	i++;
	return (i);
}
