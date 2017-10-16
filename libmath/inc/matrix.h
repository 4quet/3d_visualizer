/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:19:18 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:22:35 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libmath.h"

typedef struct	s_mtx
{
	float		*value;
	size_t		width;
	size_t		height;
}				t_mtx;

t_mtx			*mtx_new(size_t width, size_t height);
t_mtx			*mtx_identity(size_t size);
t_mtx			*mtx_copy(t_mtx const *mtx);

void			mtx_set(t_mtx *mtx, size_t x, size_t y, float value);
float			mtx_get(t_mtx const *mtx, size_t x, size_t y);

t_mtx			*mtx_sub(t_mtx const *m1, t_mtx const *m2);
t_mtx			*mtx_mult(t_mtx const *m1, t_mtx const *m2);
void			mtx_zero(t_mtx *mtx);
void			mtx_free(t_mtx **mtx);

t_mtx			*mtx_translate(float const x, float const y, float const z);
t_mtx			*mtx_scale(float const factor);
t_mtx			*mtx_transf(t_mtx *mtx, t_mtx *transformation);

t_mtx			*mtx_perspective(float angle, float ratio,
								float near, float far);

#endif
