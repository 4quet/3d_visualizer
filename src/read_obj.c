/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:03:24 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 15:03:59 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int	count_spaces(char const *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static void	get_amounts(FILE *file, size_t *v_amount, size_t *f_amount)
{
	char	buffer[256];

	while (fgets(buffer, 256, file) != NULL)
	{
		if (strncmp(buffer, "v ", 2) == 0)
			*v_amount += 1;
		else if (strncmp(buffer, "f ", 2) == 0)
			*f_amount += count_spaces(buffer) - 2;
	}
}

static void	get_values(FILE *file, float *model_vertices, float *v)
{
	size_t	i;
	char	buffer[256];

	i = 0;
	while (fgets(buffer, 256, file) != NULL)
	{
		if (sscanf(buffer, "v %f %f %f", &v[i], &v[i + 1], &v[i + 2]) == 3)
			i += 3;
		else if (strncmp(buffer, "f ", 2) == 0)
			get_face_vertices(model_vertices, buffer + 2, v);
	}
}

void		read_obj(char const *path, t_model *model)
{
	FILE	*file;
	float	*v;
	size_t	v_amount;
	size_t	f_amount;

	v = NULL;
	v_amount = 0;
	f_amount = 0;
	file = fopen(path, "r");
	if (!file)
		exit_failure("failed to open obj file");
	get_amounts(file, &v_amount, &f_amount);
	rewind(file);
	if (v_amount == 0)
		exit_failure("no vertices in file");
	if ((v = (float *)malloc(sizeof(float) * v_amount * 3)) == NULL)
		exit_failure("malloc failed");
	model->size = f_amount * 9;
	if ((model->vertices = (float *)malloc(sizeof(float) *
					model->size)) == NULL)
		exit_failure("malloc failed");
	get_values(file, model->vertices, v);
	get_bounding_box(model);
	free(v);
	fclose(file);
}
