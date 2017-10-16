/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:57:47 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:07:53 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	mtx_get(t_mtx const *mtx, size_t x, size_t y)
{
	if (!mtx)
		return (0);
	if (x >= mtx->height || y >= mtx->width)
		return (0);
	return (mtx->value[mtx->height * y + x]);
}
