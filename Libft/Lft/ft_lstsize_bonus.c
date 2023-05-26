/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:56:34 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 18:16:32 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../Includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (lst != NULL)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
