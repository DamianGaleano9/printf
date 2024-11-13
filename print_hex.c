/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <marvin@student.42.fr>              +#+  +:+      +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:38:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 11:38:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*new_string(unsigned int val, int *strlen)
{
	int					i;
	unsigned int		tmp;
	char				*str;

	i = 0;
	tmp = val;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	print_hex(unsigned int val, int asci)
{
	unsigned int	tmp_hexa;
	char			*hex_str;
	int				i;
	int				*len_str;

	len_str = &i;
	tmp_hexa = val;
	hex_str = new_string(val, len_str);
	if (!hex_str)
		return (0);
	while (tmp_hexa != 0)
	{
		if ((tmp_hexa % 16) < 10)
			hex_str[i] = tmp_hexa % 16 + '0';
		else
			hex_str[i] = (tmp_hexa % 16) + asci;
		tmp_hexa = tmp_hexa / 16;
		i--;
	}
	ft_putstr_fd(hex_str, 1);
	i = ft_strlen(hex_str);
	free(hex_str);
	if (val == 0)
		i += print_char('0');
	return (i);
}

// int main() {
//     // Casos de prueba:
    
//     // Caso 1: valor 0
//     printf("Hexadecimal de 0: ");
//     print_hex(0, 'a');  // Imprime '0' en minúsculas
//     printf("\n");

//     // Caso 2: valor positivo pequeño
//     printf("Hexadecimal de 42: ");
//     print_hex(42, 'a');  // Debería imprimir '2a'
//     printf("\n");

//     // Caso 3: valor grande
//     printf("Hexadecimal de 255: ");
//     print_hex(255, 'a');  // Debería imprimir 'ff'
//     printf("\n");

//     // Caso 4: valor con letras en mayúsculas
//     printf("Hexadecimal de 255 con mayúsculas: ");
//     print_hex(255, 'A');  // Debería imprimir 'FF'
//     printf("\n");

//     // Caso 5: valor con letras en minúsculas
//     printf("Hexadecimal de 255 con minúsculas: ");
//     print_hex(255, 'a');  // Debería imprimir 'ff'
//     printf("\n");

//     return 0;
// }
