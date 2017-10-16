#version 410
uniform vec3 viewPos = vec3(0.0, 0.0, -5.0);
uniform vec3 lightPos = vec3(-2.0, 0.0, -3.0);
uniform vec3 lightColor;

uniform sampler2D texSampler;
uniform float textureLevel;

in vec3 Normal;
in vec3 FragPos;
in vec3 Color;
in vec2 UV;

out vec4 color;

void main () {
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	
	float ambientStrength = 0.3;
	vec3 ambient = ambientStrength * lightColor;
	
	float specularStrength = 0.5;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256);
	vec3 specular = specularStrength * spec * lightColor;
	
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	
	vec4 tex = texture(texSampler, UV);
	vec4 tmp = mix(vec4(Color, 1.0), tex, textureLevel);
	vec3 result = (ambient + diffuse + specular) * tmp.rgb;
	color = vec4(result, 1.0);
}
