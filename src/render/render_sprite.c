/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:32 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:57:59 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	sort_order(t_game *game, t_pair	*orders)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < game->sprite_cnt)
	{
		j = 0;
		while (j < game->sprite_cnt - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_game *game)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair *)malloc(sizeof(t_pair) * game->sprite_cnt);
	i = 0;
	while (i < game->sprite_cnt)
	{
		sprites[i].first = game->sprite_distance[i];
		sprites[i].second = game->sprite_order[i];
		i++;
	}
	sort_order(game, sprites);
	i = 0;
	while (i < game->sprite_cnt)
	{
		game->sprite_distance[i] = sprites[game->sprite_cnt - i - 1].first;
		game->sprite_order[i] = sprites[game->sprite_cnt - i - 1].second;
		i++;
	}
	free(sprites);
}

void	get_sprites_dist(t_game *game)
{
	int		i;
	double	sprite_dist_x;
	double	sprite_dist_y;

	i = 0;
	while (i < game->sprite_cnt)
	{
		game->sprite_order[i] = i;
		sprite_dist_x = (game->param.pos_x - game->sprite[i].x) * \
										(game->param.pos_x - game->sprite[i].x);
		sprite_dist_y = (game->param.pos_y - game->sprite[i].y) * \
										(game->param.pos_y - game->sprite[i].y);
		game->sprite_distance[i] = sprite_dist_x + sprite_dist_y;
		i++;
	}
	sort_sprites(game);
}

void	render_sprite(t_game *game)
{
	int	i;

	i = 0;
	get_sprites_dist(game);
	while (i < game->sprite_cnt)
	{
		set_sprite_param(game, i);
		get_sprite_tex(game, i);
		i++;
	}
}
