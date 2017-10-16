/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:48:24 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:10:40 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vector	*vector_cross(t_vector const *v1, t_vector const *v2)
{
	t_vector	*ret;

	if (!v1 || !v2 || v1->height != 3 || v2->height != 3)
		return (NULL);
	ret = mtx_new(1, 3);
	ret->value[0] = v1->value[1] * v2->value[2] - v1->value[2] * v2->value[1];
	ret->value[1] = v1->value[2] * v2->value[0] - v1->value[0] * v2->value[2];
	ret->value[2] = v1->value[0] * v2->value[1] - v1->value[1] * v2->value[0];
	return (ret);
}
