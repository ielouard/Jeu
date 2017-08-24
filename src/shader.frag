#version 120

//Coordonee means coordinates in french

varying vec3 coordonnee_3d;
varying vec3 coordonnee_3d_locale;
varying vec3 normale;
varying vec4 color;

uniform sampler2D texture;

vec3 light=vec3(0.5,0.5,5.0);


void main (void)
{
    //Vectors for illumination calculation
    vec3 n = normalize(normale);
    vec3 d = normalize(light-coordonnee_3d_locale);
    vec3 r = reflect(d,n);
    vec3 o = normalize(-coordonnee_3d_locale);

    //Illumination calculation
    float diffuse  = 0.7*clamp(dot(n,d),0.0,1.0);
    float specular = 0.2*pow(clamp(dot(r,o),0.0,1.0),128.0);
    float ambiant  = 0.2;

    vec4 white = vec4(1.0,1.0,1.0,0.0);

    // retrieving the texture
    vec2 tex_coord     = gl_TexCoord[0].xy;
    vec4 color_texture = texture2D(texture,tex_coord);
    vec4 color_final   = color*color_texture;

    //Final color
    gl_FragColor = (ambiant+diffuse)*color_final+specular*white;

}
