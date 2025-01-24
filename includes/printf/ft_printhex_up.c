/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:10:13 by ilhannou          #+#    #+#             */
/*   Updated: 2024/11/14 19:21:23 by ilhannou         ###   ########.fr       */
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

static void	put_hex_upper(unsigned int n)
{
	char	*hexa_base;

	hexa_base = "0123456789ABCDEF";
	if (n >= 16)
		put_hex_upper(n / 16);
	write(1, &hexa_base[n % 16], 1);
}

int	ft_printhex_up(unsigned int n)
{
	put_hex_upper(n);
	return (count_hex(n));
}
