/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:43:23 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:09:47 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_sub(t_mtx const *m1, t_mtx const *m2)
{
	t_mtx	*new;
	size_t	x;
	size_t	y;

	if (!m1 || !m2 || m1->width != m2->width || m1->height != m2->height)
		return (NULL);
	new = mtx_new(m1->width, m1->height);
	x = 0;
	while (x < new->height)
	{
		y = 0;
		while (y < new->width)
		{
			mtx_set(new, x, y, mtx_get(m1, x, y) - mtx_get(m2, x, y));
			y++;
		}
		x++;
	}
	return (new);
}
