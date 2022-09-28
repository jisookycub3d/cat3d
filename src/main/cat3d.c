/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 13:35:00 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);		// init gamd and set mlx
	check_arg(argc, argv);
	parse_map(&game, argv[1]);
	start_game(&game);
	return (0);
}
