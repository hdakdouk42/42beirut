/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:39:32 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/26 19:52:09 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_print_char('-');
		len += ft_print_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_print_char('-');
		n = -n;
	}
	if (n > 9)
		len += ft_print_nbr(n / 10);
	len += ft_print_char(n % 10 + '0');
	return (len);
}
