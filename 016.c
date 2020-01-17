#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char line[ 1024 ];
	char list[ 4 ][ 15 ];
	char* ptr = NULL;
	
	int l1, l2, l3, num_ticket, counter;
	int prize[ 7 ], sum;
	
	for( l1 = 0; l1 < 4; l1++ )
	{
		gets( line );
		ptr = &line[ 0 ];
		l2 = 0;
		while( ptr != NULL && *ptr != '\n' && *ptr != '\0' && *ptr != EOF )
		{
			if( *ptr >= 48 && *ptr <= 57 )
			{
				list[ l1 ][ l2 ] = *ptr;
				l2++;
			}
			if( l2 >= 8 )
			{
				break;
			}
			ptr++;
		}
		list[ l1 ][ 8 ] = '\0';
	}
	
	gets( line );
	ptr = &line[ 0 ];
	num_ticket = atoi( ptr );
	for( l1 = 0; l1 < 7; l1++ )
	{
		prize[ l1 ] = 0;
	}
	sum = 0;
	
	for( l1 = 0; l1 < num_ticket; l1++ )
	{
		gets( line );
		line[ 8 ] = '\0';
		if( strcmp( line, list[ 0 ] ) == 0 )
		{
			prize[ 0 ]++;
		}
		else
		{
			for( l2 = 1; l2 < 4; l2++ )
			{
				counter = 7;
				for( l3 = 7; l3 >= 0; l3-- )
				{
					if( line[ l3 ] == list[ l2 ][ l3 ] )
					{
						if( l3 <= 5 )
						{
							counter--;
						}
					}
					else
					{
						break;
					}
				}
				if( counter < 7 )
				{
					prize[ counter ]++;
					break;
				}
			}
		}
	}
	sum = prize[ 0 ]*2000000 + prize[ 1 ]*200000 + prize[ 2 ]*40000 + prize[ 3 ]*10000 + prize[ 4 ]*4000 + prize[ 5 ]*1000 + prize[ 6 ]*200;
	
	for( l1 = 0; l1 < 7; l1++ )
	{
		if( l1 < 6 )
		{
			printf("%d ", prize[ l1 ] );
		}
		else
		{
			printf("%d\n", prize[ l1 ] );
		}
	}
	printf("%d\n", sum );
	return 0;
}
