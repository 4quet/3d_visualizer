/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 18:24:54 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:17:11 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

static t_mtx	*set_values(
		t_vector const *f,
		t_vector const *s,
		t_vector const *u,
		t_vector const *eye)
{
	t_mtx	*result;

	result = mtx_identity(4);
	mtx_set(result, 0, 0, vector_get(s, 0));
	mtx_set(result, 0, 1, vector_get(s, 1));
	mtx_set(result, 0, 2, vector_get(s, 2));
	mtx_set(result, 1, 0, vector_get(u, 0));
	mtx_set(result, 1, 1, vector_get(u, 1));
	mtx_set(result, 1, 2, vector_get(u, 2));
	mtx_set(result, 2, 0, -vector_get(f, 0));
	mtx_set(result, 2, 1, -vector_get(f, 1));
	mtx_set(result, 2, 2, -vector_get(f, 2));
	mtx_set(result, 0, 3, -vector_dot(s, eye));
	mtx_set(result, 1, 3, -vector_dot(u, eye));
	mtx_set(result, 2, 3, vector_dot(f, eye));
	return (result);
}

t_mtx			*mtx_lookat(
		t_vector const *eye,
		t_vector const *center,
		t_vector const *up)
{
	t_vector	*f;
	t_vector	*s;
	t_vector	*u;
	t_mtx		*result;

	if (!eye || !center || !up ||
			eye->height != 3 || center->height != 3 || up->height != 3)
		return (NULL);
	f = mtx_sub(center, eye);
	vector_normalize(f);
	s = vector_cross(f, up);
	vector_normalize(s);
	u = vector_cross(s, f);
	result = set_values(f, s, u, eye);
	mtx_free(&f);
	mtx_free(&s);
	mtx_free(&u);
	return (result);
}
