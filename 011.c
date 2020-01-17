#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[ 1024 ];
	char* ptr = NULL;
	int** matrix = NULL;
	int num_picture, l1, l2, l3, l4, l5, row, column, size;
	int sum_tmp, sum;
	
	gets( line );
	ptr = &line[ 0 ];
	num_picture = atoi( ptr );
	
	for( l1 = 0; l1 < num_picture; l1++ )
	{
		gets( line );
		ptr = &line[ 0 ];
		row = atoi( ptr );
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		column = atoi( ptr );
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		size = atoi( ptr );
//		printf("row: %d, column: %d, size: %d\n", row, column, size );
		matrix = ( int** )malloc( sizeof( int* )*row );
		for( l2 = 0; l2 < row; l2++ )
		{
			matrix[ l2 ] = ( int* )malloc( sizeof( int )*column );
			
			gets( line );
			
			ptr = &line[ 0 ];
			l3 = 0;
			while( ptr != NULL && *ptr != '\0' && *ptr != '\n' && *ptr != EOF )
			{
				if( *ptr == 45 )
				{
					ptr++;
					matrix[ l2 ][ l3 ] = atoi( ptr );
					matrix[ l2 ][ l3 ] = -1 * matrix[ l2 ][ l3 ];
					l3++;
					while( *ptr >= 48 && *ptr <= 57 )
					{
						ptr++;
					}
				}
				else if( *ptr >= 48 && *ptr <= 57 )
				{
					matrix[ l2 ][ l3 ] = atoi( ptr );
					l3++;
					while( *ptr >= 48 && *ptr <= 57 )
					{
						ptr++;
					}
				}
				else
				{
					ptr++;
				}
			}
		}
		
		sum = 0;
		for( l2 = 0; l2 < row - size + 1; l2++ )
		{
			for( l3 = 0; l3 < column - size + 1; l3++ )
			{
				sum_tmp = 0;
				
				for( l4 = 0; l4 < size; l4++ )
				{
					for( l5 = 0; l5 < size; l5++ )
					{
						sum_tmp = sum_tmp + matrix[ l2 + l4 ][ l3 + l5 ];
					}
				}
				if( sum_tmp > sum || sum == 0 )
				{
					sum = sum_tmp;
				}
			}
		}
		printf("%d\n", sum );
		
		/*
		for( l2 = 0; l2 < row; l2++ )
		{
			for( l3 = 0; l3 < column; l3++ )
			{
				printf("%d ", matrix[ l2 ][ l3 ] );
			}
			printf("\n");
		}
		*/
	}
	
	
	
	return 0;
}
