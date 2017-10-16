/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:49:14 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/05 16:53:36 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_scale(float const factor)
{
	t_mtx	*mtx;

	mtx = mtx_identity(4);
	mtx_set(mtx, 0, 0, factor);
	mtx_set(mtx, 1, 1, factor);
	mtx_set(mtx, 2, 2, factor);
	return (mtx);
}
