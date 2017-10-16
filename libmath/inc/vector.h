/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:30:31 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 16:04:35 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libmath.h"

typedef	t_mtx	t_vector;

t_vector		*vector_new3(float x, float y, float z);
float			vector_get(t_vector const *v, size_t index);

float			vector_length(t_vector const *v);
void			vector_normalize(t_vector *v);

t_vector		*vector_cross(t_vector const *v1, t_vector const *v2);
float			vector_dot(t_vector const *v1, t_vector const *v2);

t_vector		*triangle_face_normal(
					t_vector *v1,
					t_vector *v2,
					t_vector *v3);

t_mtx			*mtx_lookat(
					t_vector const *eye,
					t_vector const *center,
					t_vector const *up);

#endif
