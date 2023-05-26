/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:52:39 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 18:17:28 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char *) s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((unsigned char)*(str + i) == (unsigned char)c)
			return (str + i);
		i--;
	}
	return (0);
}
