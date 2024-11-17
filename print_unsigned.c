/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damian <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:48:26 by damian            #+#    #+#             */
/*   Updated: 2024/11/17 17:48:26 by damian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_digit(unsigned int num)
{
	if (num > 9)
		print_unsigned(num / 10);
	if (num <= 9)
	{
		ft_putchar_fd(num + 48, 1);
		return ;
	}
	ft_putchar_fd((num % 10) + 48, 1);
}

int	print_unsigned(unsigned int num)
{
	unsigned int	i;

	print_digit(num);
	i = 1;
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}
