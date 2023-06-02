/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:06:53 by clbernar          #+#    #+#             */
/*   Updated: 2023/06/02 12:00:13 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// valgrind --suppressions=ignore_readline_leaks.supp --leak-check=full --show-leak-kinds=all

// Cette fonction fait office de split en conservant l'input
// Et en separant chaque partie separe par des espaces
// pour les mettre sous forme de token
char	*get_token_value(char *input, char delimiter)
{
	static char	*next;
	char		*start;

	if (input != NULL)
		next = input;
	else if (!next)
		return (NULL);
	while (*next && *next == delimiter)
		next++;
	if (*next == '\0')
		return (NULL);
	start = next;
	while (*next && *next != delimiter)
		next++;
	if (*next != '\0')
		*next++ = '\0';
	return (start);
}

// Cette fonction renvoie le type du token envoye en argument
t_token_type	get_token_type(char *token_value)
{
	int	len;

	len = ft_strlen(token_value);
	if (ft_strncmp(token_value, "|", len) == 0)
		return (T_PIPE);
	else if (ft_strncmp(token_value, "<", len) == 0)
		return (T_LR);
	else if (ft_strncmp(token_value, ">", len) == 0)
		return (T_RR);
	else if (ft_strncmp(token_value, "<<", len) == 0)
		return (T_HEREDOC);
	else if (ft_strncmp(token_value, ">>", len) == 0)
		return (T_APPEND);
	else
		return (T_WORD);
}

void	lexer(t_token **lst, char *input)
{
	char			*token_value;
	t_token_type	token_type;
	t_token			*new;

	token_value = get_token_value(input, DELIMITER);
	while (token_value != NULL)
	{
		token_type = get_token_type(token_value);
		new = create_token(token_type, token_value);
		add_to_list(lst, new);
		token_value = get_token_value(NULL, DELIMITER);
	}
	new = create_token(T_EOF, "");
	add_to_list(lst, new);
}
