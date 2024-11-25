/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:34:47 by damian            #+#    #+#             */
/*   Updated: 2024/11/25 19:37:53 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{	
	ft_putchar_fd(c, 1);
	return (1);
}
// int	main(void)
// {
// 	char d = 'D';
// 	printf("char is %c\n", d);
// 	return(0);
// }