/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:26:49 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:08:17 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_last_char(const char *format)
{
	const char	*p;

	p = format;
	while (*p)
		p++;
	if (*(p - 1) == '%' && *(p - 2) != '%')
		return (1);
	return (0);
}

static int	ft_printf_helper(const char *p, int *count, va_list args)
{
	if (*p == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (*p == 's')
		*count += ft_putstr(va_arg(args, const char *));
	else if (*p == 'p')
		*count += ft_putptr(va_arg(args, void *));
	else if (*p == 'd' || *p == 'i')
		*count += ft_putnbr(va_arg(args, int));
	else if (*p == 'u')
		*count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*p == 'x')
		*count += ft_puthex(va_arg(args, unsigned int), false);
	else if (*p == 'X')
		*count += ft_puthex(va_arg(args, unsigned int), true);
	else if (*p == '%')
		*count += ft_putchar('%');
	else
	{
		*count += ft_putchar('%');
		*count += ft_putchar(*p);
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	const char	*p;
	va_list		args;

	count = 0;
	p = format;
	if (check_last_char(format))
		return (255);
	va_start(args, format);
	while (*p)
	{
		if (*p == '%')
		{
			p++;
			if (*p)
				ft_printf_helper(p, &count, args);
		}
		else
		{
			count += ft_putchar(*p);
		}
		p++;
	}
	va_end(args);
	return (count);
}
