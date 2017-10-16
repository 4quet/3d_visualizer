/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:51:23 by lfourque          #+#    #+#             */
/*   Updated: 2016/09/30 17:23:28 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	mtx_zero(t_mtx *mtx)
{
	ft_bzero(mtx->value, mtx->width * mtx->height * sizeof(float));
}
