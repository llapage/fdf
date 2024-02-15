/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <llapage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:23:15 by llapage           #+#    #+#             */
/*   Updated: 2023/06/30 17:08:02 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_coord	*coord;

	coord = NULL;
	if (argc != 2)
		return (1);
	parsing(&coord, argv[1]);
	create_window(coord);
	system("leaks fdf");
	return (0);
}
