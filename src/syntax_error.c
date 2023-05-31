/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:35:20 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/31 13:49:08 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	check_syntax(char *input)
{
	if (check_redirection(input) == 0)
	{
		ft_printf("Syntax error\n");
		return (0);
	}
	return (1);
}

int	check_redirection(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (0);
	
	return (1);
}
