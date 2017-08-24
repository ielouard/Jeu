
#ifndef MAT4_HPP
#define MAT4_HPP

#include <iostream>

struct vec3;

/** 4x4 matrix structure */

struct mat4
{
    /** Initialize the matrix to identity */
    mat4();
    /** Initialize the matrix with values */
    mat4(float x00,float x01,float x02,float x03,
         float x10,float x11,float x12,float x13,
         float x20,float x21,float x22,float x23,
         float x30,float x31,float x32,float x33);

    /** Obtaining the values of the matrix in the form m (x, y)*/
    float operator()(int x,int y) const;

    /** Modifying the values of the matrix in the form m (x, y) =... */
    float& operator()(int x,int y);


    /**Matrix data in the form of a table */
    float M[4*4];
};

/** Matrix product*/
mat4 operator*(const mat4& m1,const mat4& m2);

/** Apply mat4 on a vec3*/
vec3 operator*(const mat4& m1,const vec3& m2);

/**Retrieves a pointer to the data of the matrix */
const float *pointeur(const mat4& m);

/** Calculates the transpose of a matrix */
mat4 transpose(const mat4& m);

/** Constructs a rotation matrix whose axis is: (axis_x, axis_y, axis_z) and the given angle*/
mat4 matrice_rotation(float angle,float axe_x,float axe_y,float axe_z);

/** Constructs a projection matrix */
//mat4 matrice_projection(float L,float H,float d_min,float d_max);
mat4 matrice_projection(float fov,float aspect,float d_min,float d_max);

/** Constructs a matrix with only zeros */
mat4 matrice_zeros();

/** Displaying a matrix on the command line*/
std::ostream& operator<<(std::ostream& sout,const mat4& m);

#endif
