/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_face_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:30:58 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 16:03:30 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vector	*triangle_face_normal(
		t_vector *v1,
		t_vector *v2,
		t_vector *v3)
{
	t_vector	*u;
	t_vector	*v;
	t_vector	*normal;

	u = mtx_sub(v2, v1);
	v = mtx_sub(v3, v1);
	normal = vector_cross(u, v);
	mtx_free(&u);
	mtx_free(&v);
	mtx_free(&v1);
	mtx_free(&v2);
	mtx_free(&v3);
	return (normal);
}
