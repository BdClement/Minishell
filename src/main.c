/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:05:32 by clbernar          #+#    #+#             */
/*   Updated: 2023/06/02 16:11:25 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// Pour les Tests
void	display_list(t_token **lst)
{
	t_token	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		ft_printf("Type: %d ; Value: %s\n", tmp->type,
			tmp->value);
		tmp = tmp->next;
	}
}

void	minishell(void)
{
	char		*input;
	t_token		*lst;
	// t_token		*prev; A voir si besoin


	lst = NULL;
	while(1)
	{
		input = readline("Minishell$ ");
		if (check_syntax(input) == 1)
		{
			lexer(&lst, input);
			display_list(&lst);
			free_list(&lst);
			free(input);
		}
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
