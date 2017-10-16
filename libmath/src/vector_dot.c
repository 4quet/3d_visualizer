/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:58:15 by lfourque          #+#    #+#             */
/*   Updated: 2016/09/30 18:00:48 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	vector_dot(t_vector const *v1, t_vector const *v2)
{
	float	result;
	size_t	i;

	if (!v1 || !v2 || v1->height != v2->height)
		return (0);
	result = 0;
	i = 0;
	while (i < v1->height)
	{
		result += v1->value[i] * v2->value[i];
		i++;
	}
	return (result);
}
