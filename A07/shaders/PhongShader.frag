#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform UniformBufferObject {
	mat4 mvpMat;
	mat4 mMat;
	mat4 nMat;
	vec4 color;
} ubo;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir[5];
	vec3 lightPos[5];
	vec4 lightColor[5];
	float cosIn;
	float cosOut;
	vec3 eyePos;
	vec4 eyeDir;
	vec4 lightOn;
	} gubo;
	



/**********************************************************
**                                                       **
**        HERE STARTS THE PART YOU HAVE TO MODIFY	     **
**                                                       **
/*********************************************************/

// All functions returns wrong and dummy values!
// Please correctly implement them!
/*
	normalize()
	pow()
	dot()
	length()
	clamp()
	max()
	min()
*/
	
vec3 direct_light_dir(vec3 pos, int i) {
	// Direct light - direction vector
	// Direction of the light in <gubo.lightDir[i]>
	vec3 lightDir = normalize(gubo.lightDir[i]);
	return lightDir;
}

vec3 direct_light_color(vec3 pos, int i) {
	// Direct light - color
	// Color of the light in <gubo.lightColor[i].rgb>
  	return gubo.lightColor[i].rgb;
}

vec3 point_light_dir(vec3 pos, int i) {
	// Point light - direction vector
	// Position of the light in <gubo.lightPos[i]>
	vec3 lightPos = gubo.lightPos[i];
	vec3 lightDir = normalize(lightPos - pos);
	
	return lightDir;
}

vec3 point_light_color(vec3 pos, int i) {
	// Point light - color
	// Color of the light in <gubo.lightColor[i].rgb>
	// Scaling factor g in <gubo.lightColor[i].a>
	// Decay power beta: constant and fixed to 2.0
	// Position of the light in <gubo.lightPos[i]>
	//computes the color of a Point light. The basic color of the light is defined in gubo.lightColor[i].rgb. Its scaling factor g can be found in gubo.lightColor[i].a. The decay power  is constant, and it is fixed to 2.0. The position of the light is contained in gubo.lightPos[i].

	vec3 lightPos = gubo.lightPos[i];
	vec3 lightColor = gubo.lightColor[i].rgb;
	float scalingFactor = gubo.lightColor[i].a;
	float beta = 2.0;
	float distance = length(lightPos - pos);
	return pow((scalingFactor/distance), beta)*lightColor;
}

vec3 spot_light_dir(vec3 pos, int i) {
	// Spot light - direction vector
	// Direction of the light in <gubo.lightDir[i]>
	// Position of the light in <gubo.lightPos[i]>
	vec3 lightPos = gubo.lightPos[i];
	vec3 lightDir = normalize(lightPos - pos);
	
	return lightDir;
}


vec3 spot_light_color(vec3 pos, int i) {
	// Spot light - color
	// Color of the light in <gubo.lightColor[i].rgb>
	// Scaling factor g in <gubo.lightColor[i].a>
	// Decay power beta: constant and fixed to 2.0
	// Position of the light in <gubo.lightPos[i]>
	// Direction of the light in <gubo.lightDir[i]>
	// Cosine of half of the inner angle in <gubo.cosIn>
	// Cosine of half of the outer angle in <gubo.cosOut>

	vec3 lightColor = gubo.lightColor[i].rgb;
    float g = gubo.lightColor[i].a;
    float distance = length(gubo.lightPos[i] - pos);
    float attenuation = g / (distance * distance);

    // Calculate spot light effect
    vec3 lightDir = normalize(gubo.lightDir[i]);
    vec3 spotDir = normalize(gubo.lightPos[i] - pos);
    float cosAngle = dot(spotDir, lightDir);

    float spotEffect = 0.0;
    if (cosAngle > gubo.cosOut) {
        if (cosAngle > gubo.cosIn) {
            spotEffect = 1.0;
        } else {
            spotEffect = (cosAngle - gubo.cosOut) / (gubo.cosIn - gubo.cosOut);
        }
    }

    return lightColor * attenuation * spotEffect;
}


/**********************************************************
**                                                       **
**         HERE ENDS THE PART YOU HAVE TO MODIFY	     **
**                                                       **
**             DON'T TOUCH ANYTHING AFTER THIS!          **
**                                                       **
/*********************************************************/


vec3 BRDF(vec3 Albedo, vec3 Norm, vec3 EyeDir, vec3 LD) {
// Compute the BRDF, with a given color <Albedo>, in a given position characterized bu a given normal vector <Norm>,
// for a light direct according to <LD>, and viewed from a direction <EyeDir>
	vec3 Diffuse;
	vec3 Specular;
	Diffuse = Albedo * max(dot(Norm, LD),0.0f);
	Specular = vec3(pow(max(dot(EyeDir, -reflect(LD, Norm)),0.0f), 160.0f));
	
	return Diffuse + Specular;
}

void main() {
// Approximate the rendering equation for the current pixel (fragment), and return
// the solution in global variable <outColor>
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos - fragPos);
	vec3 Albedo = texture(texSampler, fragTexCoord).rgb;

	vec3 LD;	// light direction
	vec3 LC;	// light color

	vec3 RendEqSol = vec3(0);

	// First light
	LD = point_light_dir(fragPos, 0);
	LC = point_light_color(fragPos, 0);
	RendEqSol += BRDF(Albedo, Norm, EyeDir, LD) * LC         * gubo.lightOn.x;

	// Second light
	LD = point_light_dir(fragPos, 1);
	LC = point_light_color(fragPos, 1);
	RendEqSol += BRDF(Albedo, Norm, EyeDir, LD) * LC         * gubo.lightOn.x;

	// Third light
	LD = point_light_dir(fragPos, 2);
	LC = point_light_color(fragPos, 2);
	RendEqSol += BRDF(Albedo, Norm, EyeDir, LD) * LC         * gubo.lightOn.x;

	// Fourth light
	LD = direct_light_dir(fragPos, 3);
	LC = direct_light_color(fragPos, 3);
	RendEqSol += BRDF(Albedo, Norm, EyeDir, LD) * LC         * gubo.lightOn.y;

	// Fift light
	LD = spot_light_dir(fragPos, 4);
	LC = spot_light_color(fragPos, 4);
	RendEqSol += BRDF(Albedo, Norm, EyeDir, LD) * LC         * gubo.lightOn.z;

	// Indirect illumination simulation
	// A special type of non-uniform ambient color, invented for this course
	const vec3 cxp = vec3(1.0,0.5,0.5) * 0.2;
	const vec3 cxn = vec3(0.9,0.6,0.4) * 0.2;
	const vec3 cyp = vec3(0.3,1.0,1.0) * 0.2;
	const vec3 cyn = vec3(0.5,0.5,0.5) * 0.2;
	const vec3 czp = vec3(0.8,0.2,0.4) * 0.2;
	const vec3 czn = vec3(0.3,0.6,0.7) * 0.2;
	
	vec3 Ambient =((Norm.x > 0 ? cxp : cxn) * (Norm.x * Norm.x) +
				   (Norm.y > 0 ? cyp : cyn) * (Norm.y * Norm.y) +
				   (Norm.z > 0 ? czp : czn) * (Norm.z * Norm.z)) * Albedo;
	RendEqSol += Ambient         * gubo.lightOn.w;
	
	// Output color
	outColor = vec4(RendEqSol, 1.0f);
}