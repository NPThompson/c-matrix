#include"matrix.h"
#include<stdio.h>
#include<math.h>




void mat3_print(mat3 matrix, FILE* out)
{
	fprintf(out, "{\n");
	for(int i = 0; i < 3; i++)
	{	for(int j = 0; j < 3; j++)
		{
			fprintf(out, "%.2f", matrix.element[i][j]);
			if(j < 2)
				fprintf(out, ", ");
		}
		if(i < 2)
			fprintf(out, ",\n");
	}
	fprintf(out, "\n}\n");
}



void vec3_print(vec3 vector, FILE* out)
{
	fprintf(out, "{ ");
	for(int i = 0; i < 3; i++)
	{	fprintf(out, "%.2f", vector.element[i]);
		if(i < 2)
			fprintf(out, ", ");
	}
	fprintf(out, "}\n");
}



mat3 mat3_product(mat3 A, mat3 B)
{
	mat3 rv = {0,0,0,
				   0,0,0,
				   0,0,0};
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				rv.element[i][j] += A.element[i][k] * B.element[k][j];
			}
		}
	}
	
	return rv;	
}


// relies on the global constant, FLOAT_TOLERANCE to determine equality
bool mat3_equals(mat3 A, mat3 B)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(fabs(A.element[i][j] - B.element[i][j]) >= FLOAT_TOLERANCE)
				return false;
		}
	}	
	return true;
}



float mat3_max_diff(mat3 A, mat3 B)
{
	real max_diff = 0;
	real diff = 0;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			diff = fabs(A.element[i][j] - B.element[i][j]);
			
			if(diff > max_diff)
				max_diff = diff;
		}
	}	
	return max_diff;
}



vec3 mat3_transform(mat3 T, vec3 v)
{
	vec3 rv = {0,0,0};
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			rv.element[i] += T.element[i][j] * v.element[j];
		}
	}
	
	return rv;
}



// relies on the global constant, FLOAT_TOLERANCE to determine equality
bool vec3_equals(vec3 A, vec3 B)
{
	for(int i = 0; i < 3; i++)
	{
		if(fabs(A.element[i] - B.element[i]) >= FLOAT_TOLERANCE)
			return false;
	}	
	return true;
}



real vec3_dot( vec3 u, vec3 v)
{
	real rv = 0.0;
	
	for(int i = 0; i < 3; i++)
	{
		rv += u.element[i] * v.element[i];
	}
	
	return rv;
}



vec3 vec3_cross( vec3 v, vec3 w)
{
	vec3 rv =
	{ v.element[1] * w.element[2] - w.element[1] * v.element[2],
	  v.element[2] * w.element[0] - w.element[2] * v.element[0],
	  v.element[0] * w.element[1] - w.element[0] * v.element[1]};	

    return rv;
}



real vec3_length( vec3 v )
{
	real rv = 0.0;
	
	for(int i = 0; i < 3; i++)
	{
		rv += v.element[i] * v.element[i];
	}
	
	return sqrt(rv);
}