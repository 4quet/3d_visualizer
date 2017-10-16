/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_perspective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:53:17 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:10:52 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_perspective(float angle, float ratio, float near, float far)
{
	t_mtx	*mtx;
	float	tan_half_angle;

	mtx = mtx_new(4, 4);
	tan_half_angle = tanf(angle / 2.0);
	mtx_set(mtx, 0, 0, 1.0 / (ratio * tan_half_angle));
	mtx_set(mtx, 1, 1, 1.0 / (tan_half_angle));
	mtx_set(mtx, 2, 2, -(far + near) / (far - near));
	mtx_set(mtx, 3, 2, -1.0);
	mtx_set(mtx, 2, 3, -(2.0 * far * near) / (far - near));
	return (mtx);
}
