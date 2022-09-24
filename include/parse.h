/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:59:08 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/24 09:01:54 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

enum e_words
{
	WALL = 1 << 0,
	EMPTY = 1 << 1,
	DIRECTION = 1 << 3,
	DOOR = 1 << 4	
};

#endif
