/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:48:20 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 20:19:13 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAM_H
# define PARAM_H

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3

# define KEY_W 13       
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53 

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_param
{
	int			x;
	int			y;
}				t_param;

void	init_param(t_param *param);

#endif
