/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:41:24 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:09:24 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_copy(t_mtx const *mtx)
{
	t_mtx	*copy;

	if (!mtx)
		return (NULL);
	copy = mtx_new(mtx->width, mtx->height);
	ft_memcpy(copy->value, mtx->value,
			mtx->width * mtx->height * sizeof(float));
	return (copy);
}
