/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:20:44 by ilhannou          #+#    #+#             */
/*   Updated: 2024/11/29 16:02:09 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printstr(char *str);
int	ft_printint(int n);
int	ft_printchar(int c);
int	ft_printunsigned(unsigned int n);
int	ft_printptr(void *ptr);
int	ft_printhex(unsigned int n);
int	ft_printhex_up(unsigned int n);

#endif
