/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:28:13 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 21:27:00 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include "../include/param.h"

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
}
