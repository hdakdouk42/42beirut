/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:32:40 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/29 22:07:05 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (format == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len = ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len = ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		len = ft_print_hexa(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		len = ft_print_hexa(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		len = ft_print_percent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_print_char(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
