/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:05:02 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:08:09 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	mtx_set(t_mtx *mtx, size_t x, size_t y, float value)
{
	if (!mtx || x >= mtx->height || y >= mtx->width)
		return ;
	mtx->value[mtx->height * y + x] = value;
}
