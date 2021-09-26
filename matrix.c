#include"matrix.h"
#include<stdio.h>
#include<math.h>




void float3x3_print(float3x3 matrix, FILE* out)
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



void float3_print(float3 vector, FILE* out)
{
	fprintf(out, "{ ");
	for(int i = 0; i < 3; i++)
	{	fprintf(out, "%.2f", vector.element[i]);
		if(i < 2)
			fprintf(out, ", ");
	}
	fprintf(out, "}\n");
}



float3x3 float3x3_product(float3x3 A, float3x3 B)
{
	float3x3 rv = {0,0,0,
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
bool float3x3_equals(float3x3 A, float3x3 B)
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



float float3x3_max_diff(float3x3 A, float3x3 B)
{
	float max_diff = 0;
	float diff = 0;
	
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



float3 float3x3_transform(float3x3 T, float3 v)
{
	float3 rv = {0,0,0};
	
	
	
	return rv;
}



// relies on the global constant, FLOAT_TOLERANCE to determine equality
bool float3_equals(float3 A, float3 B)
{
	for(int i = 0; i < 3; i++)
	{
		if(fabs(A.element[i] - B.element[i]) >= FLOAT_TOLERANCE)
			return false;
	}	
	return true;
}


