/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:46:06 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/25 22:52:12 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void	*wall_n;
	void	*wall_s;
	void	*wall_w;
	void	*wall_e;
	void	*door;
}				t_image;

#endif