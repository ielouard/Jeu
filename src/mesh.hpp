#ifndef MESH_HPP
#define MESH_HPP

#include "vertex_opengl.hpp"
#include "triangle_index.hpp"
#include <vector>
#include <string>

struct mat4;
struct vec3;

/** A mesh structure*/
struct mesh
{
    /**The information (coord, color, normal, texture) by vertices*/
    std::vector<vertex_opengl> vertex;

    /** la connectivite des triangles */
    std::vector<triangle_index> connectivity;
};

/** load off file*/
mesh load_off_file(const std::string& filename);
/** Loading an obj file (potentially handling the texture) */
mesh load_obj_file(const std::string& filename);

/** Calculates the normals of the mesh passed in parameter */
void update_normals(mesh* m);
/** Gives a uniform color to the mesh passed in parameter */
void fill_color(mesh* m,const vec3& color);
/** Each vertex of the mesh receives a color corresponding to its normal*/
void fill_color_normal(mesh* m);

/** Applies the matrix passed in parameter to the set of vertices of the mesh*/
void apply_deformation(mesh* m,const mat4 T);
/**Inverses the sense of all normal meshes*/
void invert_normals(mesh* m);

#endif
