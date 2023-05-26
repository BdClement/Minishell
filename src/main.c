/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:05:32 by clbernar          #+#    #+#             */
/*   Updated: 2023/05/26 18:27:37 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_printf("Invalid input. No arguments required. (%s)\n", argv[1]);
	return (0);
}
