/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 19:16:30 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/01 12:12:44 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vector	*vector_new3(float x, float y, float z)
{
	t_vector	*new;

	new = mtx_new(1, 3);
	new->value[0] = x;
	new->value[1] = y;
	new->value[2] = z;
	return (new);
}
