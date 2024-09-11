/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:14:30 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/29 21:59:55 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long a)
{
	int	len;

	len = 0;
	if (a / 16 > 0)
		len = len + ft_print_hex(a / 16);
	a = a % 16;
	if (a < 10)
		len += ft_print_char(a + '0');
	else
		len += ft_print_char(a - 10 + 'a');
	return (len);
}

int	ft_print_ptr(void *p)
{
	unsigned long	address;
	int				len;

	len = 0;
	address = (unsigned long)p;
	if (p == NULL)
	{
		ft_print_str("(nil)");
		return (ft_strlen("(nil)"));
	}
	len += ft_print_char('0');
	len += ft_print_char('x');
	len += ft_print_hex(address);
	return (len);
}
