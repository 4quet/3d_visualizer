/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 09:17:44 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:10:01 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*quat_to_matrix(t_quat *quat)
{
	float	*q;
	t_mtx	*mtx;

	q = quat->value;
	mtx = mtx_new(4, 4);
	mtx_set(mtx, 3, 3, 1.0);
	mtx_set(mtx, 0, 0, 1.0 - 2.0 * (q[1] * q[1] + q[2] * q[2]));
	mtx_set(mtx, 0, 1, 2.0 * (q[0] * q[1] - q[2] * q[3]));
	mtx_set(mtx, 0, 2, 2.0 * (q[0] * q[2] + q[3] * q[1]));
	mtx_set(mtx, 1, 0, 2.0 * (q[0] * q[1] + q[2] * q[3]));
	mtx_set(mtx, 1, 1, 1.0 - 2.0 * (q[0] * q[0] + q[2] * q[2]));
	mtx_set(mtx, 1, 2, 2.0 * (q[1] * q[2] - q[3] * q[0]));
	mtx_set(mtx, 2, 0, 2.0 * (q[0] * q[2] - q[3] * q[1]));
	mtx_set(mtx, 2, 1, 2.0 * (q[1] * q[2] + q[3] * q[0]));
	mtx_set(mtx, 2, 2, 1.0 - 2.0 * (q[0] * q[0] + q[1] * q[1]));
	mtx_free(&quat);
	return (mtx);
}
