/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:27:56 by lfourque          #+#    #+#             */
/*   Updated: 2016/09/30 17:21:10 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_new(size_t width, size_t height)
{
	t_mtx	*mtx;

	mtx = (t_mtx *)malloc(sizeof(t_mtx));
	mtx->value = (float *)malloc(sizeof(float) * (width * height));
	mtx->width = width;
	mtx->height = height;
	mtx_zero(mtx);
	return (mtx);
}
