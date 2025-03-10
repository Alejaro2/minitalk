/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:03 by alejaro2          #+#    #+#             */
/*   Updated: 2024/11/26 19:27:11 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_print_num(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
