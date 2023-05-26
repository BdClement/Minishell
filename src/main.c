/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:05:32 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 20:15:39 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	minishell(void)
{
	char		*input;
	const char	*prompt;

	while(1)
	{
		prompt = "Minishell$ ";
		input = readline(prompt);
		// ft_printf("%s\n", input);
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_printf("Invalid input. No arguments required. (%s)\n", argv[1]);
	else
		minishell();
	return (0);
}
