/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejaro2 <alejaro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:22 by alejaro2          #+#    #+#             */
/*   Updated: 2024/11/27 18:31:02 by alejaro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specific_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += (ft_print_char((va_arg(args, int))));
	else if (specifier == 's')
		count += (ft_print_str((va_arg(args, char *))));
	else if (specifier == 'd' || specifier == 'i')
		count += (ft_print_num(va_arg(args, int)));
	else if (specifier == 'u')
		count += (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		count += (ft_print_hexadecimal(va_arg(args, unsigned int), specifier));
	else if (specifier == 'p')
		count += (ft_print_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		count += (ft_print_char(specifier));
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += specific_format(*(++str), args);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
