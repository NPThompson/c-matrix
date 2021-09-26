// matrix.h

// N.P.Thompson (2021)
// This is free and open-source software

// defines these types:
// 3-dimensional vectors and 3x3 matrices
// 'real' is considered the base type, typedef'd to mean float. 
// denoted vec3 and mat3, respectively, in case others are ever added

// intended use cases are quick-and-dirty graphics, number crunching,
// or simple games/simulations.



#ifndef MATRIX_H
#define MATRIX_H



#include<stdio.h>


// for the purposes of comparing matrices, 
// I consider two floats as good as equal if
// they differ by less than one trillionth 
//
// redefine this value or use one of the 
// <type>_max_diff() functions to 
// use a different tolerance
#ifndef FLOAT_TOLERANCE
#define FLOAT_TOLERANCE 0.000000000001
#endif

typedef int bool;
#define true 1
#define false 0



typedef float real;



typedef struct 
{
	real element[3];
} vec3;

typedef struct
{
	real element[3][3];
} mat3;



// ==== vec3 operations ====
// prints as a brace-enclosed initializer, just like C: {1,2,3}
void vec3_print(  vec3, FILE*);
bool vec3_equals( vec3, vec3);
real vec3_dot(    vec3, vec3);



// ==== mat3 operations ====
void mat3_print(    mat3, FILE*);
bool mat3_equals(   mat3, mat3);
mat3 mat3_product(  mat3, mat3);
real mat3_max_diff( mat3, mat3);



// ==== other operations ====
// Ax -> y, where x and y are vectors and A is a matrix
vec3 mat3_transform( mat3, vec3);



#endif