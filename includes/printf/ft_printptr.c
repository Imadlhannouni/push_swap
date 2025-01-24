/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:41:31 by ilhannou          #+#    #+#             */
/*   Updated: 2024/12/30 19:14:00 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_ptr(unsigned long long n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		counter++;
		n /= 16;
	}
	return (counter);
}

static void	put_hex(unsigned long long ad)
{
	char	*hexa_base;

	hexa_base = "0123456789abcdef";
	if (ad >= 16)
		put_hex(ad / 16);
	write(1, &hexa_base[ad % 16], 1);
}

int	ft_printptr(void *ptr)
{
	unsigned long long	address;

	write(1, "0x", 2);
	address = (unsigned long long)ptr;
	put_hex(address);
	return (count_ptr(address) + 2);
}
