/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:19:19 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 03:21:45 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

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
