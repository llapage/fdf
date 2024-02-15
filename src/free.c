/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:43:18 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 15:07:14 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	lstdelone_fdf(t_coord *coord)
{
	if (coord)
		free(coord);
}

void	lstclear_fdf(t_coord *coord, int finish)
{
	t_coord	*tmp;

	if (coord)
	{
		while (coord != NULL)
		{
			tmp = NULL;
			if (coord->next)
				tmp = (coord)->next;
			lstdelone_fdf(coord);
			coord = tmp;
		}
	}
	if (finish == 1)
		exit (1);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}
