/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:42:14 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 18:16:22 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "../Includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*last;

	tmp = lst;
	last = lst;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}
