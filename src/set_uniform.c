/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:38:21 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:55:33 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_uniform_mtx(GLuint shader, char const *name, float *mtx_value)
{
	GLuint	location;

	location = glGetUniformLocation(shader, name);
	glUniformMatrix4fv(location, 1, GL_FALSE, mtx_value);
}
