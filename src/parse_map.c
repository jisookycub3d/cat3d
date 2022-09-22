/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:20:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/22 16:35:57 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

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

int	*get_num(char **strs)
{
	int	num;
	int	*arr;
	int	i;
	int	j;

	i = 0;
	arr = ft_calloc(3, sizeof(int));
	while (strs[i])
	{
		j = 0;
		num = 0;
		while (strs[i][j])
		{
			num = num * 10 + (strs[i][j] - 48);
			j++;
		}
		arr[i] = num;
		i++;
	}
	return (arr);
}

int	check_unsigned_char(char *str)
{
	int	i;
	unsigned int	num;
	
	i = 0;
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - 48);
		if (num > 2147483647)
			return (1);
		i++;
	}
	if (num >= 0 && num < 256)
		return (0);
	return (1);
}

int	rgb_atoi(t_game *game, char **rgb, char flag)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_isdigit(rgb[i]))
			return (1);
		if (check_unsigned_char(rgb[i]))
			return (1);
		i++;
	}
	if (i > 3)
		return (1);
	if (flag == 'C')
		game->rgb.ceiling = get_num(rgb);
	else
		game->rgb.floor = get_num(rgb);
	return (0);
}

int	get_rgb(t_game *game, char *line)
{
	int		i;
	char	**rgb;
	char	flag;

	i = 0;
	if (line[0] == 'C')
		flag = 'C';
	else
		flag = 'F';
	line++;
	while (*line == ' ')
		line++;
	rgb = ft_split(line, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		return (1);
	if (rgb_atoi(game, rgb, flag))
	{
		ft_free(rgb);
		return(1);
	}
	ft_free(rgb);
	return (0);
}

int	init_ceiling(t_game *game, char *line, int *complited)
{
	if (*complited == 1)
		return (0);
	if (ft_strncmp(line, "C ", 2))
		return (0);
	if (game->rgb.ceiling)
		return (1);
	if (get_rgb(game, line))
	{
		free(game->rgb.ceiling);
		return (1);
	}
	*complited = 1;
	return (0);
}

int	init_floor(t_game *game, char *line, int *complited)
{
	if (*complited == 1)
		return (0);
	if (ft_strncmp(line, "F ", 2))
		return (0);
	if (game->rgb.floor)
		return (1);
	if (get_rgb(game, line))
	{
		free(game->rgb.floor);
		return (1);
	}
	*complited = 1;
	return (0);
}

int	init_rgb(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int	i;
	int	completed;

	i = 0;
	completed = 0;
	while (gnl[i] == ' ')
		i++;
	if (init_ceiling(game, &gnl[i], &completed))
		return (1);
	if (init_floor(game, &gnl[i], &completed))
		return (1);
	if (completed)
		*checked = 1;
	if (game->map.map && completed)
		*map_flag = 1;
	return (0);
}

void	open_texture(t_game *game, char *path, char *gnl)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free_game(game);
		if (gnl)
			free(gnl);
		printf("%s\n", strerror(errno));
		exit(0);
	}
	close(fd);	
}

int	init_north(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "NO ", 3))
		return (0);
	if (game->texture.north)
		return (1);
	i = 2;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.north = ft_strdup(&line[i]);
	open_texture(game, game->texture.north, gnl);
	*completed = 1;
	return (0);
}

int	init_south(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "SO ", 3))
		return (0);
	if (game->texture.south)
		return (1);
	i = 2;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.south = ft_strdup(&line[i]);
	open_texture(game, game->texture.south, gnl);
	*completed = 1;
	return (0);
}

int	init_east(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "EA ", 3))
		return (0);
	if (game->texture.east)
		return (1);
	i = 2;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.east = ft_strdup(&line[i]);
	open_texture(game, game->texture.east, gnl);
	*completed = 1;
	return (0);
}

int	init_west(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "WE ", 3))
		return (0);
	if (game->texture.west)
		return (1);
	i = 2;
	while (line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.west = ft_strdup(&line[i]);
	open_texture(game, game->texture.west, gnl);
	*completed = 1;
	return (0);
}

int	init_texture(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int	i;
	int	completed;

	i = 0;
	completed = 0;
	while (gnl[i] == ' ')
		i++;
	if (init_north(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_south(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_east(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_west(game, &gnl[i], &completed, gnl))
		return (1);
	if (completed)
		*checked = 1;
	if (game->map.map && completed)
		*map_flag = 1;
	return (0);
}

void	make_map(t_game *game, char *line)
{
	int		i;
	int		j;
	char	**strs;
	char	**tmp;

	i = 0;
	j = 0;
	while (game->map.map[i])
		i++;
	strs = ft_calloc(i + 2, sizeof(char *));
	while (j < i)
	{
		strs[j] = game->map.map[j];
		j++;
	}
	strs[j] = line;
	tmp = game->map.map;
	game->map.map = strs;
	free(tmp);
}

int	init_map(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int		i;
	char	*line;

	i = 0;
	if (*checked == 1)
		return (0);
	while (gnl[i] == ' ')
		i++;
	if (gnl[i] == '1')
		*checked = 1;
	else
		return (0);
	if (*map_flag)
		return (1);
	line = ft_strdup(gnl);
	if (!game->map.map)
	{
		game->map.map = ft_calloc(2, sizeof(char *));
		game->map.map[0] = line;
		game->map.map[1] = 0;
	}
	else
		make_map(game, line);
	return (0);
}

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

int	 check_texture(t_game *game)
{
	if (game->texture.east && game->texture.west && game->texture.north && game->texture.south)
		return (0);
	return (1);
}

int	check_rgb(t_game *game)
{
	if (game->rgb.ceiling && game->rgb.floor)
		return (0);
	return (1);
}

int	check_valid(t_game *game)
{
	if (check_texture(game))
		return (1);
	// if (check_map(game))
	// 	return (1);
	if (check_rgb(game))
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
