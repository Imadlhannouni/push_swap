/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:20:46 by ilhannou          #+#    #+#             */
/*   Updated: 2024/10/27 13:36:00 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len1;
	char	*s2;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1) + 1;
	s2 = malloc(len1);
	if (!s2)
		return (NULL);
	while (i < len1 - 1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
