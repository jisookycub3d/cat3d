/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:40:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 14:52:02 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	rgb_to_i(int *arr)
{
	return (arr[0] * 16 * 16 * 16 * 16 + arr[1] * 16 * 16 + arr[2]);
}

void	bit_mask(char *c)
{
	if (*c == '1')
		*c = WALL;
	else if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W')
		*c = DIRECTION;
	else if (*c == ' ')
		*c = SPACE;
	else if (*c == '0')
		*c = EMPTY;
	else if (*c == 'D')
		*c = DOOR;
}

