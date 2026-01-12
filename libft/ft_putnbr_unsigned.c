/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:28:55 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:07:51 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		i;
	char	digit;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_unsigned(n / 10);
	}
	digit = '0' + (n % 10);
	write(1, &digit, 1);
	i++;
	return (i);
}
