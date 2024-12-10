/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazo-ga <dmazo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:45:25 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 18:46:41 by dmazo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char const *c)
{
	int	len;

	if (c == NULL)
		return (ft_print_string ("(null)"));
	len = 0;
	while (*c != '\0')
	{
		len += ft_print_char (*c);
		c++;
	}
	return (len);
}
// int main(void)
// {
// 	int len = ("damian");
// 	printf("longitud de cadena %d\n", len);
// 	return(0);
// }