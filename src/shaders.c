/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 15:42:10 by lfourque          #+#    #+#             */
/*   Updated: 2016/10/17 16:55:58 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char		*read_shader(char const *path)
{
	FILE	*file;
	char	*content;
	size_t	size;

	file = fopen(path, "r");
	if (!file)
		exit_failure("Can't open specified shader file");
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	content = (char *)malloc(sizeof(char) * (size + 1));
	fread(content, sizeof(char), size, file);
	fclose(file);
	content[size] = 0;
	return (content);
}

static GLuint	new_shader(int type, const GLchar *content)
{
	GLuint	id;
	GLint	success;

	id = glCreateShader(type);
	glShaderSource(id, 1, &content, NULL);
	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success)
		exit_failure("some shader does not compile");
	return (id);
}

void			load_shaders(t_env *env)
{
	const GLchar	*vertex_content;
	const GLchar	*fragment_content;
	GLuint			vertex_id;
	GLuint			fragment_id;
	GLint			success;

	vertex_content = read_shader("shaders/MVP.vert");
	fragment_content = read_shader("shaders/LightingAndTexture.frag");
	vertex_id = new_shader(GL_VERTEX_SHADER, vertex_content);
	fragment_id = new_shader(GL_FRAGMENT_SHADER, fragment_content);
	env->shader = glCreateProgram();
	glAttachShader(env->shader, fragment_id);
	glAttachShader(env->shader, vertex_id);
	glLinkProgram(env->shader);
	glGetProgramiv(env->shader, GL_LINK_STATUS, &success);
	if (!success)
		exit_failure("shader program does not link");
	glDeleteShader(vertex_id);
	glDeleteShader(fragment_id);
	free((char *)vertex_content);
	free((char *)fragment_content);
}
