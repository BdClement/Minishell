/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:36:43 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/31 12:48:50 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// Cette fonction cree un element de type t_token
t_token	*create_token(t_token_type type, char *token_value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = type;
	new_token->value = token_value;
	new_token->next = NULL;
	// new_token->prev = NULL;
	return (new_token);
}

// Cette fonction ajoute un nouveau token a la liste chainee
void	add_to_list(t_token **lst, t_token *new)
{
	t_token	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		// new->prev = tmp;
	}
}

// Cette fonction free la liste chainee de token
void	free_list(t_token **lst)
{
	t_token	*tmp;

	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
