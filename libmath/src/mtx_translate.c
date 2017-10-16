/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:25:17 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/06 12:43:39 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_translate(float const x, float const y, float const z)
{
	t_mtx	*result;

	result = mtx_identity(4);
	mtx_set(result, 0, 3, x);
	mtx_set(result, 1, 3, y);
	mtx_set(result, 2, 3, z);
	return (result);
}
