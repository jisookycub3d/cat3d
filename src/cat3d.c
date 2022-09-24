/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 19:34:13 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	check_arg(argc, argv);
	parse_map(&game, argv[1]);
	start_game(&game);
	return (0);
}