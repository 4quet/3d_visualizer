/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:38:44 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:05:17 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mtx	*mtx_identity(size_t size)
{
	size_t	i;
	t_mtx	*mtx;

	if (size < 1)
		return (NULL);
	i = 0;
	mtx = mtx_new(size, size);
	while (i < size)
	{
		mtx_set(mtx, i, i, 1);
		i++;
	}
	return (mtx);
}
