/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 09:16:45 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/04 09:22:56 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_rotate(t_vector *axis, float const angle)
{
	float	half_angle;
	float	sin_half_angle;
	t_quat	*quat;

	vector_normalize(axis);
	half_angle = angle * 0.5;
	sin_half_angle = sin(half_angle);
	quat = mtx_new(1, 4);
	quat->value[0] = axis->value[0] * sin_half_angle;
	quat->value[1] = axis->value[1] * sin_half_angle;
	quat->value[2] = axis->value[2] * sin_half_angle;
	quat->value[3] = cos(half_angle);
	return (quat_to_matrix(quat));
}
