
#pragma once

#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>


/** A 2D vector structure*/

struct vec2
{
    /** coordinates x */
    float x;
    /** coordinates y */
    float y;

    /** Constructor vector (0,0)*/
    vec2();
    /** Constructor vector (x,y) */
    vec2(float x_param,float y_param);

    /** Vector sum */
    vec2& operator+=(const vec2& v);
    /** Vector Difference */
    vec2& operator-=(const vec2& v);
    /** Multiplication by a scalar*/
    vec2& operator*=(float s);
    /** Division by a scalar*/
    vec2& operator/=(float s);
};


/** Vector norm */
float norm(const vec2& v);
/** Dot product*/
float dot(const vec2& v0,const vec2& v1);

/** Returns a vector of the same direction of norm 1 */
vec2 normalize(const vec2& v);

/** Displaying a vector on the command line*/
std::ostream& operator<<(std::ostream& sout,const vec2& m);

/** Vector sum*/
vec2 operator+(const vec2& v0,const vec2& v1);
/** Difference vector */
vec2 operator-(const vec2& v0,const vec2& v1);
/** Multiplication by a scalar*/
vec2 operator*(const vec2& v0,float s);
/** Multiplication by a scalar*/
vec2 operator*(float s,const vec2& v0);
/** Division by a scalar*/
vec2 operator/(const vec2& v0,float s);




#endif
