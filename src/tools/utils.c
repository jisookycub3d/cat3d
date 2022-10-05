/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:40:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/05 18:04:11 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	rgb_to_i(int *arr)
{
	return (arr[0] * 16 * 16 * 16 * 16 + arr[1] * 16 * 16 + arr[2]);
}

char	bit_mask(char c)
{
	if (c == '1')
		c = WALL;
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		c = EMPTY;
	else if (c == ' ')
		c = SPACE;
	else if (c == 'D')
		c = DOOR;
	return (c);
}

