/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:31:39 by lfourque          #+#    #+#             */
/*   Updated: 2016/09/30 17:39:05 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	vector_length(t_vector const *v)
{
	float	len;
	size_t	i;

	len = 0;
	i = 0;
	while (i < v->height)
	{
		len += v->value[i] * v->value[i];
		i++;
	}
	return (sqrt(len));
}
