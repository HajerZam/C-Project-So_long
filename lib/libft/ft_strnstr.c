/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:36:03 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/06 13:05:47 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *src, const char *tar, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*tar)
		return ((char *)src);
	i = 0;
	while (src[i] && i < len)
	{
		j = 0;
		while (tar[j] && (i + j) < len && src[i + j] && src[i + j] == tar[j])
		{
			j++;
		}
		if (!tar[j])
			return ((char *)&src[i]);
		i++;
	}
	return (NULL);
}
