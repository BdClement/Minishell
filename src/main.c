/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:05:32 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/30 18:44:05 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	minishell(void)
{
	char		*input;
	const char	*prompt;
	t_token		*lst;
	t_token		*tmp;
	// t_token		*prev;


	lst = NULL;
	// while(1)
	// {
		prompt = "Minishell$ ";
		input = readline(prompt);
		lexer(&lst, input);
		tmp = lst;
		while (tmp != NULL)
		{
			ft_printf("Type : %d Value : %s\n\n", tmp->type, tmp->value);
			// if (tmp->prev != NULL)
			// {
			// 	prev = tmp->prev;
			// 	printf("previous == %s\n", prev->value);
			// }
			tmp = tmp->next;
		}
		// tmp = tmp->prev;
		// ft_printf("%s\n", tmp->value);
		free_list(&lst);
		// Free lst !!
		free(input);
	// }
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
