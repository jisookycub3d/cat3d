/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:20:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 03:21:49 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

// int	check_map(char **map)
// {
// 	int	i;
	
// 	i = 0;
// 	while (map[i])
// 		i++;
// 	if ()
// 	//대각선 임의채우기
// 	//판별법 : 동서남북으로만
// }

int	init_content(t_game *game, char *gnl)
{
	//빈 줄 건너뛰기
	//동서남북 파일 저장 및 중복 및 열리는지 체크
	//rgb체크
	//맵 체크
	// 맵 3줄이상이어야함
	// 모든 요소 맵, 동서남북, 천장 바닥 이런거 또 나오면 안됨 (중복처리)
	// 공백 워드스플릿해야함 (맵빼고)
	// 맵은 무조건 1을 만남
	// map flag는 texture or rgb에서 map이 있으면 켜줌
	int	i;
	int	checked;
	static int	map_flag;

	i = 0;
	checked = 0;
	while (gnl[i] == ' ')
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
		//check_map
		free_game(game);
		exit_with_message("Error");
	}
	// if (check_map(game->map.map))
	// {
	// 	ft_free(game->map.map);
	// 	exit_with_message("Error");
	// }
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
		printf("%d", i);
		printf("%s\n", game->map.map[i]);
		i++;
	}
	return (0);
}
