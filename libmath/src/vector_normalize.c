/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:25:48 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:11:08 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	vector_normalize(t_vector *v)
{
	size_t	i;
	float	len;

	if (!v)
		return ;
	len = vector_length(v);
	i = 0;
	while (i < v->height)
	{
		v->value[i] = v->value[i] / len;
		i++;
	}
}
