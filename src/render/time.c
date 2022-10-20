/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:08:08 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:08:29 by jisookim         ###   ########.fr       */
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
