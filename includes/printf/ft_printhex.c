/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:05:30 by ilhannou          #+#    #+#             */
/*   Updated: 2024/11/14 17:13:44 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	put_hex(unsigned int n)
{
	char	*hexa_base;

	hexa_base = "0123456789abcdef";
	if (n >= 16)
		put_hex(n / 16);
	write(1, &hexa_base[n % 16], 1);
}

int	ft_printhex(unsigned int n)
{
	put_hex(n);
	return (count_hex(n));
}
