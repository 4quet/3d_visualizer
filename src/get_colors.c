/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:32:40 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:05:13 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_colors(t_model *model)
{
	size_t	i;
	size_t	n;
	float	level;

	model->colors = (float *)malloc(sizeof(float) * model->size);
	if (model->colors == NULL)
		exit_failure("malloc failed");
	i = 0;
	while (i < model->size)
	{
		level = 0.3 + (i % 27 / 3) * 0.1;
		n = 0;
		while (n < 9)
		{
			model->colors[i + n] = level;
			n++;
		}
		i += 9;
	}
}
