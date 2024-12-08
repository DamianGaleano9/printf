/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:48:26 by damian            #+#    #+#             */
/*   Updated: 2024/11/28 14:28:48 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_unsigned(n / 10);
		len += ft_print_unsigned(n % 10);
	}
	else
		len += ft_print_char(n + '0');
	return (len);
}
// int	main(void)
// {	
// 	unsigned int num = 999;
// 	print_unsigned(num);
// 	return(0);
// }