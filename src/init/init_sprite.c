#include "../../include/cat3d.h"

void	get_sprite_pos(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.imap[i][j] & SPRITE)
			{
				game->sprite[cnt].texture = 5;
				game->sprite[cnt].x = j + 0.5;
				game->sprite[cnt].y = i + 0.5;
				game->map.imap[i][j] = EMPTY;
				cnt++;
			}
			j++;
		}
		i++;
	}
}

void	init_sprite(t_game *game)
{
	if (!game->sprite_cnt)
		return ;
	game->sprite_order = ft_calloc(game->sprite_cnt, sizeof(int));
	game->sprite_distance = ft_calloc(game->sprite_cnt, sizeof(double));
	game->sp_param.zbuffer = ft_calloc(S_WIDTH, sizeof(double));
	game->sprite = ft_calloc(game->sprite_cnt, sizeof(t_sprite));
	get_sprite_pos(game);
}