/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:01:05 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 20:05:35 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/Includes/libft.h"
# include "../Libft/Includes/ft_printf.h"
# include "../Libft/Includes/get_next_line.h"

// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>

typedef enum s_token_type {
	T_WORD,
	T_ARG,
	T_PIPE,
	T_LR,
	T_RR,
	T_HEREDOC,
	T_APPEND,
	T_NL,
	T_EOF,
}				t_token_type;

typedef struct s_token {
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}				t_token;

#endif
