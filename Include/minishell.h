/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:01:05 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/30 18:53:14 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/Includes/libft.h"
# include "../Libft/Includes/ft_printf.h"
# include "../Libft/Includes/get_next_line.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

# define DELIMITER ' '

typedef enum s_token_type {
	T_WORD,
	T_PIPE,
	T_LR,
	T_RR,
	T_HEREDOC,
	T_APPEND,
	T_EOF,
}				t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

// LEXER PART
// LIST
void			free_list(t_token **lst);
void			add_to_list(t_token **lst, t_token *new);
t_token			*create_token(t_token_type type, char *token_value);
// t_token	*lst_last(t_token **lst);
// TOKENISATION
char			*get_token_value(char *input, char delimiter);
void			lexer(t_token **lst, char *input);
t_token_type	get_token_type(char *token_value);

#endif
