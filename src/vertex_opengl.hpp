#ifndef VERTEX_OPENGL_HPP
#define VERTEX_OPENGL_HPP

#include "vec3.hpp"
#include "vec2.hpp"

/** A triangle vertex displayed by OpenGL */
struct vertex_opengl
{
    /** Summit 3D coordinates */
    vec3 position;
    /** Summit normal */
    vec3 normal;
    /** Summit color */
    vec3 color;
    /** Summit color coordinates */
    vec2 texture;

    /** Default constructor */
    vertex_opengl();
    /** Special constructor */
    vertex_opengl(const vec3& position,
                  const vec3& normal,
                  const vec3& color,
                  const vec2& texture);
};

#endif
