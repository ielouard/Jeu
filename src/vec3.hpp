
#pragma once

#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>


/** A 3D vector structure*/

struct vec3
{
    /** coordinate x */
    float x;
    /** coordinate y */
    float y;
    /** coordinate z */
    float z;

    /** Vector costructor (0,0,0) */
    vec3();
    /** Vector constructor (x,y,z) */
    vec3(float x_param,float y_param,float z_param);

    /** Vector sum */
    vec3& operator+=(const vec3& v);
    /** Vector difference */
    vec3& operator-=(const vec3& v);
    /** Multiplication by a scalar */
    vec3& operator*=(float s);
    /** Division by a scalar*/
    vec3& operator/=(float s);
};


/** Norm of a vector */
float norm(const vec3& v);
/**Dot product */
float dot(const vec3& v0,const vec3& v1);
/** Cross product */
vec3 cross(const vec3& v0,const vec3& v1);

/** Returns a vector of the same direction of norm 1 */
vec3 normalize(const vec3& v);

/** Displaying a vector on the command line*/
std::ostream& operator<<(std::ostream& sout,const vec3& m);

/** Vector sum*/
vec3 operator+(const vec3& v0,const vec3& v1);
/** Vector Difference */
vec3 operator-(const vec3& v0,const vec3& v1);
/** Multiplication by a scalar */
vec3 operator*(const vec3& v0,float s);
/** Multiplication by a scalar */
vec3 operator*(float s,const vec3& v0);
/** Division by a scalar */
vec3 operator/(const vec3& v0,float s);






#endif
