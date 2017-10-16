/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 18:10:04 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/03 17:25:08 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	vector_get(t_vector const *v, size_t index)
{
	if (!v || index >= v->height)
		return (0);
	return (v->value[index]);
}
