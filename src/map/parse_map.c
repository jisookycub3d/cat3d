/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:20:07 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/03 18:11:00 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

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

void	init_imap(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strslen(game->map.map);
	game->map.imap = ft_calloc(i, sizeof(int *));
	while (j < i)
	{
		game->map.imap[j] = ft_calloc(ft_strlen(game->map.map[j]), sizeof(int));
		j++;
	}
}

void	make_imap(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	init_imap(game);
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			game->map.imap[i][j] = game->map.map[i][j];
			j++;
		}
		i++;
	}
    game->map.width = j - 1;
    game->map.height = i - 1;
}

int	parse_map(t_game *game, char *mapfile)
{
	char	*gnl;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	gnl = get_next_line(fd);
	get_lines(game, gnl, fd);
	make_imap(game);
	return (0);
}
