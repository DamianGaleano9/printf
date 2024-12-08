/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:38 by marvin            #+#    #+#             */
/*   Updated: 2024/11/24 15:36:02 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (ft_print_string("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		len += ft_print_char('-');
	}
	if (n >= 10)
		len += ft_print_char(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}

// int main() {
//     int result;

//     printf("Imprimir 9:\n");
//     result = print_int(9);  // Imprime 42
//     printf("\nNúmero de caracteres impresos: %d\n", result);
// 	    return 0;
// }