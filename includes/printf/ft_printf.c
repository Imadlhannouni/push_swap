/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:06:41 by ilhannou          #+#    #+#             */
/*   Updated: 2024/12/30 19:13:36 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getformat(const char *format, unsigned int *i, va_list *args)
{
	unsigned int	return_counter;

	return_counter = 0;
	if (format[*i] == 'c')
		return_counter += ft_printchar(va_arg(*args, int));
	else if (format[*i] == 's')
		return_counter += ft_printstr(va_arg(*args, char *));
	else if (format[*i] == 'p')
		return_counter += ft_printptr(va_arg(*args, void *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return_counter += ft_printint(va_arg(*args, int));
	else if (format[*i] == 'x')
		return_counter += ft_printhex(va_arg(*args, unsigned int));
	else if (format[*i] == 'X')
		return_counter += ft_printhex_up(va_arg(*args, unsigned int));
	else if (format[*i] == 'u')
		return_counter += ft_printunsigned(va_arg(*args, unsigned int));
	else if (format[*i] == '%')
	{
		ft_printchar('%');
		return (1);
	}
	return (return_counter);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	return_length;

	i = 0;
	return_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (!format)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			return_length += ft_getformat(format, &i, &args);
		}
		else
		{
			return_length += ft_printchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (return_length);
}
