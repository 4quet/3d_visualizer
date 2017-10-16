/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_transf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:07:00 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:45:40 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_transf(t_mtx *mtx, t_mtx *transformation)
{
	t_mtx	*ret;

	ret = mtx_mult(mtx, transformation);
	mtx_free(&mtx);
	mtx_free(&transformation);
	return (ret);
}
