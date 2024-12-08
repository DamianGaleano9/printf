/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_poin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:05:17 by dmazo-ga          #+#    #+#             */
/*   Updated: 2024/12/04 12:32:13 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_poin(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_print_string("(nill)");
	else
	{
		len += ft_print_string("0x");
		len += ft_print_hexa(n, 'x');
	}
	return (len);
}
