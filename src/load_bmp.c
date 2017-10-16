/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 11:41:24 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 14:13:55 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	load_bmp(char const *path, t_texture *texture)
{
	FILE			*file;
	unsigned char	header[54];
	unsigned int	data_pos;
	unsigned int	image_size;

	file = fopen(path, "r");
	if (!file)
		exit_failure("Can't open specified texture file");
	if (fread(header, 1, 54, file) != 54)
		exit_failure("BMP file not well formated");
	if (header[0] != 'B' || header[1] != 'M')
		exit_failure("BMP file not well formated");
	data_pos = *(int*)&(header[0x0A]);
	image_size = *(int*)&(header[0x22]);
	texture->width = *(int*)&(header[0x12]);
	texture->height = *(int*)&(header[0x16]);
	if (image_size == 0)
		image_size = texture->width * texture->height * 3;
	if (data_pos == 0)
		data_pos = 54;
	texture->data = (unsigned char *)malloc(sizeof(unsigned char) * image_size);
	if (texture->data == NULL)
		exit_failure("malloc failed");
	fread(texture->data, 1, image_size, file);
	fclose(file);
}
