// matrix-test.c

// I, N.P.Thompson made this. (2021)
// This software is free and open source

// this program demonstrates the correctness
// of the matrix and vector math implemented
// in matrix.c

// if anything goes wrong, this program will 
// print to the standard output with a brief
// explanation of what happened and what was
// expected to happen. 

// if everything goes right, this program 
// will print nothing.

 

#include"matrix.h"
#include<stdio.h>




// these macros take two arguments, compare them,
// and complain if they aren't equal
#define MATRIX_EXPECTED(A,B)\
 if(!mat3_equals(A,B))\
 { printf("%s() failed:\n " #A " = \n", __func__);\
   mat3_print(A, stdout);\
   printf("\n expected ");\
   mat3_print(B, stdout);\
 }

 
 
#define VECTOR_EXPECTED(A,B)\
 if(!vec3_equals(A,B))\
 { printf("%s() failed:\n " #A " = \n", __func__);\
   vec3_print(A, stdout);\
   printf("\n expected ");\
   vec3_print(B, stdout);\
 }
 

 
#define SCALAR_EXPECTED(A,B)\
 if(A != B)\
 { printf("%s() failed:\n " #A " = ", __func__);\
   fprintf(stdout, "%.2f", A);\
   fprintf(stdout, "\n expected %d\n", B);\
 }
 

mat3 I = {1,0,0,0,1,0,0,0,1};


// following the mathematical convention,
// the first subscript, i, gives the row
// the second, j, gives the column, with 
// the left and uppermost corner being 
// the beginning of the indices.
//
// of course, we make allowances for the
// computer by treating 0 as the first 
// index and not 1
void test_indices_notation_is_correct()
{
	mat3 M = 
	{
		1,2,3,
		4,5,6,
		7,8,9
	};
	
	SCALAR_EXPECTED(M.element[0][0], 1);	
	SCALAR_EXPECTED(M.element[1][1], 5);
	SCALAR_EXPECTED(M.element[1][2], 6);
	SCALAR_EXPECTED(M.element[2][0], 7);
} 



void test_multiplication_by_identity_matrix_yields_same()
{
	mat3 M = {1,2,3,4,5,6,7,8,9};
	
	MATRIX_EXPECTED( mat3_product(M, I), M);
}



void test_multiplication_of_matrices_is_correct()
{
	mat3 A = {1,1,1,
				  1,1,1,
				  1,1,1};
				  
	mat3 B = {1,2,3,
				  1,2,3,
				  1,2,3};
				  
	mat3 C = {3,6,9,
				  3,6,9,
				  3,6,9};
	
	MATRIX_EXPECTED( mat3_product(A,B), C );
	
	
	
	mat3 D = {0,3,1,
				  1,0,1,
				  3,2,1};
				  
	mat3 E = {4,1,3,
				  2,3,0,
				  0,1,2};
				  
	mat3 F = {6,10,2,
				  4,2,5,
				  16,10,11};
	
	MATRIX_EXPECTED( mat3_product(D,E), F );
}



void test_transformation_by_identity_matrix_yields_same()
{
	vec3 v = {1,2,3};
	
	VECTOR_EXPECTED( mat3_transform(I,v), v );
}



int main(int argc, char** argv)
{	
	test_indices_notation_is_correct();
	test_multiplication_by_identity_matrix_yields_same();
	test_multiplication_of_matrices_is_correct();
	test_transformation_by_identity_matrix_yields_same();
	
	return 0;
}