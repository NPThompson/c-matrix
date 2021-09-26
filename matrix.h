// matrix.h

// defines these types:
// 3-dimensional vectors and 3x3 matrices, using floats as the base type
// denoted float3 and float3x3, respectively, in case others are ever added




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



typedef struct 
{
	float element[3];
} float3;

typedef struct
{
	float element[3][3];
} float3x3;


// prints as a brace-enclosed initializer, just like C: {1,2,3}
void float3x3_print(float3x3, FILE*);
void float3_print(float3, FILE*);



float3x3 float3x3_product(float3x3, float3x3);



bool  float3x3_equals(float3x3, float3x3);
bool  float3_equals(float3, float3);
float float3x3_max_diff(float3x3,float3x3);

float3 float3x3_transform(float3x3,float3);


#endif