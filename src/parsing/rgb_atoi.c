/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:11:02 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 03:21:53 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

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
