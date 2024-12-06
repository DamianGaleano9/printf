/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:31:43 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/12/04 12:27:39 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long n, char const arg)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += print_hexa((n / 16), arg);
	if ((n % 16) <= 9)
		len += ft_putchar_fd ((n % 16) + '0', 1);
	else if (arg == 'x' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_putchar_fd((n % 16) - 10 + 'a', 1);
	else if (arg == 'X' && (n % 16) > 9 && (n % 16) < 16)
		len += ft_putchar_fd((n % 16) - 10 + 'A', 1);
	return (len);
}
