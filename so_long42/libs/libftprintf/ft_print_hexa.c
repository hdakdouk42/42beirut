/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:22:28 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/29 16:38:20 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int n, char b)
{
	int	len;

	len = 0;
	if (n / 16 > 0)
		len += ft_print_hexa(n / 16, b);
	n = n % 16;
	if (n < 10)
		len += ft_print_char(n + '0');
	else
	{
		if (b == 'x')
			len += ft_print_char(n - 10 + 'a');
		else if (b == 'X')
			len += ft_print_char(n - 10 + 'A');
	}
	return (len);
}
