/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:35:20 by clbernar          #+#    #+#             */
/*   Updated: 2023/06/02 17:41:26 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

// Cette fonction appelle les differentes fonctions de check syntax
// puis renvoie un message d'erreur si besoin
int	check_syntax(char *input)
{
	int	syntax_error;

	syntax_error = 1;
	if (check_pipe_error(input) == 0)
		syntax_error = 0;
	else if (check_special_char(input) == 0)
		syntax_error = 0;
	if (syntax_error == 0)
	{
		ft_printf("Syntax error\n");
		return (0);
	}
	return (1);
}

// EN COURS
int	check_empty_and_double_pipe(char *input)
{
	int	i;
	int	pipe;
	int	quote_state;

	i = 0;
	pipe = 0;
	quote_state = CLOSED;
	while (input[i] != '\0')
	{
		quote_state = quote_state(input[i], quote_state);
		if (quote_state == CLOSED)
		{
			if (input[i] == '|' && pipe == 1)
				return (0);
			else if (input[i] == '|')
			{
				if (input[i + 1] == '|')
					return (0);
				pipe = 1;
				i++;
			}
			if (pipe == 1 && input[i] != ' ')
				pipe = 0;
		}
		i++;
	}
	return (1);
}

// Cette fonction check les syntax_error dues aux pipes
// D'abord elle check que le premier carcatere (hors espace) ne soit pas un pipe
// Ensuite elle check que le dernier carcatere(hors espace) ne soit pas un pipe
// Enfin qu'un pipe ne soit pas suivi d'aucune commande puis d'un autre pipe
int	check_pipe_error(char *input)
{
	int	i;
	int	pipe;

	i = 0;
	pipe = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (0);
	i = ft_strlen(input) - 1;
	while (input[i] == ' ')
		i--;
	if (input[i] == '|')
		return (0);
	if (check_empty_and_double_pipe(input) == 0)
		return (0);
	return (1);
}

// Cette fonction check si il y a une syntax_error
// du a un backslash , a un ou plusieurs carcteres speciaux
// en dehors de quotes, ou un a des quotes non fermees
int	check_special_char(char *input)
{
	int	i;
	int	prev_state;

	prev_state = CLOSED;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\\')
			return (0);
		prev_state = quotes_state(input[i], prev_state);
		if (prev_state == CLOSED && is_special_char(input[i]) == 0)
			return (0);
		i++;
	}
	if (prev_state != CLOSED)
		return (0);
	return (1);
}

// Fonction pour check si mes redirections ont bien
// un caractere autorise derriere
// int	check_redirection(char *input)
// {
// 	int	i;
// 	int	rdir_count;

// 	i = 0;
// 	rdir_count = 0;
// 	while (input[i] != '\0')
// 	{
// 		if (input[i] == '\\')
// 			return (0);
// 		while (input[i] == '<')
// 			rdir_count++;
// 		if (rdir_count > 2)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
