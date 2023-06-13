/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:47:37 by clbernar          #+#    #+#             */
/*   Updated: 2023/06/13 15:13:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	is_special_char(char c)
{
	int	i;

	i = 0;
	while (SPECIAL_CHAR[i] != '\0')
	{
		if (SPECIAL_CHAR[i] == c)
			return (0);
		i++;
	}
	return (1);
}

// Cette fonction permet garder un etat d'ouverture ou de
// fermeture des quotes pour pouvoir interpreter ou non
// certains caractere
int	quotes_state(char c, int prev_state)
{
	if (c == '\'')
	{
		if (prev_state == SINGLE_OPEN)
			return (CLOSED);
		else if (prev_state == CLOSED)
			return (SINGLE_OPEN);
	}
	else if (c == '\"')
	{
		if (prev_state == DOUBLE_OPEN)
			return (CLOSED);
		else if (prev_state == CLOSED)
			return (DOUBLE_OPEN);
	}
	return (prev_state);
}
