/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:48:26 by damian            #+#    #+#             */
/*   Updated: 2024/11/25 19:54:20 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digit(unsigned int num)
{
	if (num > 9)
		print_digit(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
}

int	print_unsigned(unsigned int num)
{
	unsigned int	i;

	if(num == 0)
	{
		ft_putchar_fd('0', 1);
		return(1);
	}

	print_digit(num);
	i = 1;
	return (0);
}
// int	main(void)
// {	
// 	unsigned int num = 999;
// 	print_unsigned(num);
// 	return(0);
// }