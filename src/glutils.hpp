/*****************************************************************************\
 * CPE Practical work                                                                    *
 * ------
 *
 * Opengl help fonctions (Dislay errors, shaders loader etc)
 * Code inspired by David Odin's code: Opengl professor at CPE Lyon
 *
 *
\*****************************************************************************/



#ifndef GL_UTILS_H
#define GL_UTILS_H

#include <vector>
#include <string>

#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/gl.h>


//Macro permettant la recherche et l'affichage des erreurs OpenGL, indique le fichier et la ligne au moment de l'appel.
#define PRINT_OPENGL_ERROR() print_opengl_error(__FILE__, __LINE__)



//Display OpenGL errors
//Affichage des erreurs OpenGL
bool print_opengl_error(const char *file, int line);

//Return OpenGL version
//Retourne la version d'OpenGL
void get_gl_version(int *major, int *minor);

//Look for a uniform variable in the shader
//Recherche une variable uniform dans le shader
GLint get_uni_loc(GLuint program, const GLchar *name);

//Loading shader from a file
// 1st argument: vertex shader file
// 2nd argument: Fragment shader file

//Chargement d'un shader un partir d'un fichier
// 1er argument: fichier contenant le vertex shader
// 2eme argument: fichier contenant le fragment shader
// Si on ne souhaite charge qu'un shader, on laissera la chaine vide "" pour l'autre nom.
GLuint read_shader(const std::string &vertex_filename,
                   const std::string &fragment_filename);



// Adapt the offset for the VBO buffers
// Param : offset (bytes)
//Decallage d'offset sur pour les buffers des VBO (un simple cast vers un pointeur)
// Le parametre doit contenir l'offset en octets
GLubyte* buffer_offset(int offset);

#endif
