#include<stdio.h>
#include<stdlib.h>
/*

	�D�ءG ��J�@�ƾ�ơA�H�Ů�j�}�A�H�ۤ϶��ǿ�X
	
	�L�{�G
		�ŧi line[ 1024 ] �@����J���Ȧs�B
		�ŧi list[ 100 ] �@���ƾ��x�s�B
		
		�� while() �j��N�ƾڱq line ��i list�G							-	( 1 ) 
			��X����G
				�Y	ptr ���ū���
				�Y	ptr ������
				�Y	ptr �������Ÿ�
				�Y	ptr �������Ÿ� 
			�Y	ptr ���Ʀr 													-	( 2 ) 
				�� list[ counter ] = atoi( ptr ) �N���Ū�i list[ ... ]
				���L��誺�Ʀr 
			�Y	�_															-	( 3 ) 
				ptr ���V�U�@�Ӧr
		
		�N list[ ... ] �H�ۤϪ����ǦL�X 									-	( 4 ) 

*/
int main()
{
	char line[ 1024 ];
	gets( line );
	
	int list[ 100 ], counter, l1, l2;
	char* ptr = NULL;
	
	ptr = &line[ 0 ];
	counter = 0;
	while( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' )	//	-> ( 1 ) 
	{
		if( *ptr >= 48 && *ptr <= 57 )									//	->	( 2 ) 
		{
			list[ counter ] = atoi( ptr );
			counter++;
			while( *ptr >= 48 && *ptr <= 57 )
			{
				ptr++;
			}
		}
		else															//	->	( 3 ) 
		{
			ptr++;
		}
	}

	for( l1 = counter-1; l1 >= 0; l1-- )								//	->	( 4 ) 
	{
		if( l1 > 0 )
			printf("%d ", list[ l1 ] );
		else if( l1 == 0 )
			printf("%d\n", list[ l1 ] );
	}
	
	
	return 0;
}
