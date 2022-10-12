#include "../../include/cat3d.h"
#include <math.h>

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
	int	i;

	i = 0;
	while (i < game->sprite_cnt)
	{
		game->sprite_order[i] = i;
		game->sprite_distance[i] = ((game->param.pos_x - game->sprite[i].x) * (game->param.pos_x - game->sprite[i].x) + (game->param.pos_y - game->sprite[i].y) * (game->param.pos_y - game->sprite[i].y));
		i++;
	}
	sort_sprites(game);
}

void	set_sprite_param(t_game *game, int i)
{
	double	int_det;

	game->sp_param.sprite_x = game->sprite[game->sprite_order[i]].x - game->param.pos_x;
	game->sp_param.sprite_y = game->sprite[game->sprite_order[i]].y - game->param.pos_y;
	int_det	= 1.0 / (game->param.plane_x * game->param.dir_y - game->param.dir_x * game->param.plane_y);
	game->sp_param.transform_x = int_det * (game->param.dir_y * game->sp_param.sprite_x - game->param.dir_x * game->sp_param.sprite_y);
	game->sp_param.transform_y = int_det * (-game->param.plane_y * game->sp_param.sprite_x + game->param.plane_x * game->sp_param.sprite_y);
	game->sp_param.sprite_screen_x = (int)(S_WIDTH / 2) * (1 + game->sp_param.transform_x / game->sp_param.transform_y);
	game->sp_param.vmove_screen = (int)(VMOVE / game->sp_param.transform_y);
	game->sp_param.sprite_height = (int)fabs((S_HEIGHT / game->sp_param.transform_y) / VDIV);
	game->sp_param.draw_start_y = -game->sp_param.sprite_height / 2 + S_HEIGHT / 2 + game->sp_param.vmove_screen;
	if (game->sp_param.draw_start_y < 0)
		game->sp_param.draw_start_y = 0;
	game->sp_param.draw_end_y = game->sp_param.sprite_height / 2 + S_HEIGHT / 2 + game->sp_param.vmove_screen;
	if (game->sp_param.draw_end_y >= S_HEIGHT)
		game->sp_param.draw_end_y = S_HEIGHT - 1;
	game->sp_param.sprite_width = (int)fabs((S_HEIGHT / game->sp_param.transform_y) / UDIV);
	game->sp_param.draw_start_x = -game->sp_param.sprite_width / 2 + game->sp_param.sprite_screen_x;
	if (game->sp_param.draw_start_x < 0)
		game->sp_param.draw_start_x = 0;
	game->sp_param.draw_end_x = game->sp_param.sprite_width / 2 + game->sp_param.sprite_screen_x;
	if (game->sp_param.draw_end_x >= S_WIDTH)
		game->sp_param.draw_end_x = S_WIDTH - 1;
}

void	get_sprite_tex(t_game *game, int i)
{
	int	stripe;
	int	tex_x;
	int	y;
	int	tex_y;
	int	color;
	int	d;

	stripe = game->sp_param.draw_start_x;
	while (stripe < game->sp_param.draw_end_x)
	{
		tex_x = (int)((256 * (stripe - (-game->sp_param.sprite_width / 2 + game->sp_param.sprite_screen_x)) * TEX_SIZE / game->sp_param.sprite_width) / 256);
		if (game->sp_param.transform_y > 0 && stripe > 0 && stripe < S_WIDTH && game->sp_param.transform_y < game->sp_param.zbuffer[stripe])
		{
			y = game->sp_param.draw_start_y;
			while (y < game->sp_param.draw_end_y)
			{
				d = (y - game->sp_param.vmove_screen) * 256 - S_HEIGHT * 128 + game->sp_param.sprite_height * 128;
				tex_y = ((d * TEX_SIZE) / game->sp_param.sprite_height) / 256;
				color = game->tex[game->sprite[game->sprite_order[i]].texture][TEX_SIZE * tex_y + tex_x];
				if ((color & 0x00FFFFFF) != 0)
					game->buf[y][stripe] = color;
				y++;
			}
		}
		stripe++;
	}
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