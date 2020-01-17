#include<stdio.h>
#include<stdlib.h>
int main()
{
	char line[ 1024 ];
	gets( line );
	
	int list[ 100 ], counter, l1, l2;
	char* ptr = NULL;
	
	ptr = &line[ 0 ];
	counter = 0;
	while( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' )
	{
		if( *ptr >= 48 && *ptr <= 57 )
		{
			list[ counter ] = atoi( ptr );
			counter++;
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

	for( l1 = counter-1; l1 >= 0; l1-- )
	{
		if( l1 > 0 )
			printf("%d ", list[ l1 ] );
		else if( l1 == 0 )
			printf("%d\n", list[ l1 ] );
	}
	
	
	return 0;
}
