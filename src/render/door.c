/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:08:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/18 01:29:42 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

long long	get_time(void)
{
	long long	now;

	now = clock();
	return (now);
}

void	update_time(t_game *game)
{
	game->time.last = game->time.now;
	game->time.now = get_time();
	game->time.deltatime = (game->time.now - game->time.last) / 1000;
}

void	close_door(t_game *game, int map_x, int map_y)
{
	game->open_door.door_offset[map_y][map_x] -= (double)game->time.deltatime / 300;
	if (game->open_door.door_offset[map_y][map_x] < 0)
	{
		game->open_door.door_offset[map_y][map_x] = 0;
		game->open_door.door_state[map_y][map_x] = CLOSE;
		game->door = 0;
	}
	printf("close%f %lld\n", game->open_door.door_offset[map_y][map_x], game->time.deltatime);
}

void	open_door(t_game *game, int map_x, int map_y)
{
	game->open_door.door_offset[map_y][map_x] += (double)game->time.deltatime / 300;
	if (game->open_door.door_offset[map_y][map_x] > 1)
	{
		game->open_door.door_offset[map_y][map_x] = 1;
		game->open_door.door_state[map_y][map_x] = OPEN;
		game->door = 0;
	}
	printf("open%f %lld\n", game->open_door.door_offset[map_y][map_x], game->time.deltatime);
}

void	door_events(t_game *game, int map_x, int map_y)
{
	if (game->open_door.door_state[map_y][map_x] == CLOSE)
		game->open_door.door_state[map_y][map_x] = OPENING;
	else if (game->open_door.door_state[map_y][map_x] == OPEN)
		game->open_door.door_state[map_y][map_x] = CLOSING;
	if (game->open_door.door_state[map_y][map_x] == OPENING)
		open_door(game, map_x, map_y);
	if (game->open_door.door_state[map_y][map_x] == CLOSING)
		close_door(game, map_x, map_y);
}

void	door(t_game *game)
{
	int	map_y;
	int	map_x;

	map_x = (int)floor(game->param.pos_x);
	map_y = (int)floor(game->param.pos_y);
	if (game->map.imap[map_y][map_x + 1] & DOOR)
		door_events(game, map_x + 1, map_y);
	if (game->map.imap[map_y][map_x - 1] & DOOR)
		door_events(game, map_x - 1, map_y);
	if (game->map.imap[map_y + 1][map_x] & DOOR)
		door_events(game, map_x, map_y + 1);
	if (game->map.imap[map_y - 1][map_x] & DOOR)
		door_events(game, map_x, map_y - 1);
	//open || close has different event
}
