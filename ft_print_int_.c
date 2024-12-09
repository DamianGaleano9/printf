/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:15:38 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 17:29:12 by dmazo-ga         ###   ########.fr       */
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
		len += ft_print_char('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_print_int(n / 10);
	len += ft_print_char((n % 10) + '0');
	return (len);
}

// int main() {
//     int result;

//     printf("Imprimir 42:\n");
//     result = ft_print_int(42);
//     printf("\nNúmero de caracteres impresos: %d\n", result);

//     ft_printf ("Usando printf: %d\n", 42);

//     return 0;
// }