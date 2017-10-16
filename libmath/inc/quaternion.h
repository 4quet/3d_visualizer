/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:17:38 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/04 09:25:13 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "libmath.h"

typedef t_vector	t_quat;

t_mtx	*quat_to_matrix(t_quat *quat);
t_mtx	*mtx_rotate(t_vector *axis, float const angle);

#endif
