/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:20:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 09:22:30 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

// 맵 3줄이상이어야함
// 모든 요소 맵, 동서남북, 천장 바닥 이런거 또 나오면 안됨 (중복처리)
// 공백 워드스플릿해야함 (맵빼고)
// 맵은 무조건 1을 만남
// map flag는 texture or rgb에서 map이 있으면 켜줌
int	init_content(t_game *game, char *gnl)
{
	int	i;
	int	checked;
	static int	map_flag;

	i = 0;
	checked = 0;
	while (is_space(gnl[i]))
		i++;
	if (gnl[i] == '\0')
	{
		if (game->map.map)
			map_flag = 1;
		return (0);
	}
	if (init_texture(game, gnl, &checked, &map_flag))
		return (1);
	if (init_map(game, gnl, &checked, &map_flag))
		return (1);
	if (init_rgb(game, gnl, &checked, &map_flag))
		return (1);
	if (!checked)
		return (1);
	return (0);
}

void	get_lines(t_game *game, char *gnl, int fd)
{
	int	i;

	while (gnl)
	{
		i = 0;
		while (gnl[i] && gnl[i] != '\n')
			i++;
		ft_strlcpy(&gnl[i], &gnl[i + 1], ft_strlen(&gnl[i]));
		if (init_content(game, gnl))
		{
			close(fd);
			free(gnl);
			free_game(game);
			exit_with_message("Error");
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	if (check_valid(game))
	{
		free_game(game);
		exit_with_message("Error");
	}
}

int	parse_map(t_game *game, char *mapfile)
{
	char	*gnl;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	gnl = get_next_line(fd);
	get_lines(game, gnl, fd);
	int i = 0;
	while (game->map.map[i])
	{
		printf("%d|", i);
		printf("%s$\n", game->map.map[i]);
		i++;
	}
	return (0);
}
