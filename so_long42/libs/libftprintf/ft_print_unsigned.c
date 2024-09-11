/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdakdouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:46:39 by hdakdouk          #+#    #+#             */
/*   Updated: 2024/06/29 16:20:04 by hdakdouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int	len;

	len = 0;
	if (num > 9)
		len += ft_print_unsigned(num / 10);
	len += ft_print_char(num % 10 + '0');
	return (len);
}
