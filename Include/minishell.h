/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:01:05 by clbernar          #+#    #+#             */
/*   Updated: 2023/06/13 16:24:27 by clbernar         ###   ########.fr       */
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
# define SPECIAL_CHAR "#&~*`();\\"
# define SINGLE_OPEN 1
# define DOUBLE_OPEN 2
# define CLOSED 3

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
}				t_token;

// LEXER PART
//		LEXER_LIST
void			free_list(t_token **lst);
void			add_to_list(t_token **lst, t_token *new);
t_token			*create_token(t_token_type type, char *token_value);
//	t_token	*lst_last(t_token **lst);
// TOKENISATION LEXER
char			*get_token_value(char *input, char delimiter);
void			lexer(t_token **lst, char *input);
t_token_type	get_token_type(char *token_value);

// SYNTAX_ERROR
int				check_syntax(char *input);
int				check_pipe_error(char *input);
int				check_empty_and_double_pipe(char *input);
int				check_redirections(char *input);
int				check_empty_redirection(char *input);
// SYNTAX_ERROR2
int				check_special_char(char *input);
int				check_bad_env_variable(char *input);

// UTILS
int				is_special_char(char c);
int				quotes_state(char c, int prev_state);

#endif
