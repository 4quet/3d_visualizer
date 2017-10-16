/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:45:51 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:07:38 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_mult(t_mtx const *m1, t_mtx const *m2)
{
	t_mtx	*result;
	size_t	x;
	size_t	y;
	size_t	i;
	float	val;

	if (!m1 || !m2 || m1->width != m2->height)
		return (NULL);
	result = mtx_new(m2->width, m1->height);
	x = -1;
	while (++x < result->height)
	{
		y = -1;
		while (++y < result->width)
		{
			i = -1;
			val = 0;
			while (++i < m1->width)
				val += mtx_get(m1, i, y) * mtx_get(m2, x, i);
			mtx_set(result, x, y, val);
		}
	}
	return (result);
}
