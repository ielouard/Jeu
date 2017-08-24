#version 120

uniform mat4 rotation_model;
uniform vec4 rotation_center_model;
uniform vec4 translation_model;

uniform mat4 rotation_view;
uniform vec4 rotation_center_view;
uniform vec4 translation_view;

uniform mat4 projection;


varying vec3 coordonnee_3d;
varying vec3 coordonnee_3d_locale;
varying vec3 normale;
varying vec4 color;


//A minimalist Vertex Shader
void main (void)
{
    //The 3D coordinates of the summit
    coordonnee_3d = gl_Vertex.xyz;

    //Application of model deformation
    vec4 p_model = rotation_model*(gl_Vertex-rotation_center_model)+rotation_center_model+translation_model;
    //Application of the deformation of the view
    vec4 p_modelview = rotation_view*(p_model-rotation_center_view)+rotation_center_view+translation_view;

    coordonnee_3d_locale = p_modelview.xyz;


    //Summit projection
    vec4 p_proj = projection*p_modelview;

    // Management of Normals
    vec4 n = rotation_view*rotation_model*vec4(gl_Normal,0.0);
    normale=n.xyz;

    //Top color
    color=gl_Color;

    //Position in the screen space
    gl_Position = p_proj;

    //Texture coordinates
    gl_TexCoord[0]=gl_MultiTexCoord0;
}
