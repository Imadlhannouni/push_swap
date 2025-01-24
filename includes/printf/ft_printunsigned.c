/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:26:00 by ilhannou          #+#    #+#             */
/*   Updated: 2024/11/13 18:45:29 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_uns(unsigned int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter += 1;
	}
	return (counter);
}

static void	ft_putnbr_uns(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_uns(n / 10);
	ft_printchar(n % 10 + '0');
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = count_uns(n);
	ft_putnbr_uns(n);
	return (len);
}
