/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:48:54 by damian            #+#    #+#             */
/*   Updated: 2024/11/25 17:20:46 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_string(unsigned long val, int *strlen)
{
	int					i;
	unsigned long		tmp;
	char				*str;

	i = 0;
	tmp = val;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = calloc(i + 1, sizeof(char));
	*strlen = i;
	return (str);
}

int	print_pointer(unsigned long val, int asc)
{
	unsigned long		tempointer;
	char				*print_str;
	int					i;
	int					*len_str;

	len_str = &i;
	tempointer = val;
	print_str = new_string(val, len_str);
	if (!print_str)
		return (0);
	i--;
	while (tempointer != 0 && i-- >= 0)
	{
		if ((tempointer % 16) < 10)
			print_str[i + 1] = (tempointer % 16) + 48;
		else
			print_str[i + 1] = (tempointer % 16) + asc;
		tempointer = tempointer / 16;
	}
	i = ft_strlen(print_str);
	i = i + print_string("0x");
	ft_putstr_fd(print_str, 1);
	free(print_str);
	if (val == 0)
		i += print_char('0');
	return (i);
}

// int	main(void)
// {
// 	unsigned long test_val_1 = 0x1A3F;
// 	unsigned long test_val_2 = 0;
// 	unsigned long test_val_3 = 0xFFFFFFFFFFFFFF;

// 	printf("Test 1: ");
// 	int len1 = print_pointer(test_val_1, 'a');
// 	printf(" (Length: %d)\n", len1);

// 	printf("Test 2: ");
// 	int len2 = print_pointer(test_val_2, 'a');
// 	printf(" (Length: %d)\n", len2);

// 	printf("Test 3: ");
// 	int len3 = print_pointer(test_val_3, 'a');
// 	printf(" (Length: %d)\n", len3);

// 	// printf(NULL);

// 	return (0);
// }