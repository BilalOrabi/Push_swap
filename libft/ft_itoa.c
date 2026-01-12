/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:44:31 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/05 21:44:31 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberlen(int n, int	*sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*sign *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_revstr(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= ((len - 1) / 2))
	{
		temp = str[len - i];
		str[len - i] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 0;
	str = malloc ((ft_numberlen(n, &sign) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = ((n % 10) * sign) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_revstr(str));
}
