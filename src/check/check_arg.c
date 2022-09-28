/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:23:45 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 14:55:25 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static int	file_extension_err(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (i && file[i] == '.' && !ft_strncmp(&file[i], ".cub", 5))
			return (0);
		if (i && file[i] == '.' && ft_strncmp(&file[i], ".cub", 5))
			return (1);
		i++;
	}
	return (1);
}

static int	invalid_file(char *file)
{
	int		fd;
	char	buf[2];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	if (!read(fd, buf, 2))
	{
		close(fd);
		return (1);
	}
	return (0);
}

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		exit_with_message("You need to enter just a argument");
	if (file_extension_err(argv[1]))
		exit_with_message("You can enter only .cub file extension");
	if (invalid_file(argv[1]))
		exit_with_message("This file is invalid");
}
