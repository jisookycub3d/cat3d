/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:20:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/21 15:42:38 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	init_content(char *gnl)
{
	//빈 줄 건너뛰기
	//동서남북 파일 저장 및 중복 및 열리는지 체크
	//rgb체크
	//맵 체크
	맵 3줄이상이어야함
	모든 요소 맵, 동서남북, 천장 바닥 이런거 또 나오면 안됨 (중복처리)
	공백 워드스플릿해야함 (맵빼고)
}

void	get_lines(t_game *game, char *gnl, int fd)
{
	while (gnl)
	{
		if (init_content(gnl))
		{
			close(fd);
			free(gnl);
			exit_with_message("Error");
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
}

int	parse_map(t_game *game, char *mapfile)
{
	char	*gnl;
	char	*last_gnl;
	int		fd;

	last_gnl = 0;
	gnl = get_next_line(fd);
	fd = open(mapfile, O_RDONLY);
	get_lines(game, gnl, fd);
	return (0);
}

//벽으로 막혀있는지