/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:46:49 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 18:16:45 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../Includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	if (s2 > s1)
	{
		while (n-- > 0)
		{
			s2[n] = s1[n];
		}
	}
	else
	{
		while (i < n)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dest);
}
