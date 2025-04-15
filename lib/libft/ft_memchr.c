/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:54:33 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/06 13:11:54 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	idx;

	if (!s)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s)[idx] == (unsigned char)c)
			return (((unsigned char *)s) + idx);
		idx++;
	}
	return (NULL);
}
