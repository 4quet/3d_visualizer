/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face_vertices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:15:20 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:03:00 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	push_vertex(float *vertices, float *v, size_t index)
{
	static size_t i = 0;

	vertices[i] = v[index * 3 - 3];
	vertices[i + 1] = v[index * 3 - 2];
	vertices[i + 2] = v[index * 3 - 1];
	i += 3;
}

void		get_face_vertices(float *vertices, char *line, float *v)
{
	size_t	t;
	size_t	index[4];
	char	*token;

	t = 0;
	while ((token = strsep(&line, " ")) != NULL)
	{
		index[t] = atoi(token);
		if (strcmp(token, "\n") == 0)
			break ;
		if (t == 4)
			exit_failure("ERROR: faces with more than 4 vertices detected");
		else if (t == 3)
		{
			push_vertex(vertices, v, index[0]);
			push_vertex(vertices, v, index[2]);
			push_vertex(vertices, v, index[3]);
		}
		else
			push_vertex(vertices, v, index[t]);
		t++;
	}
}
