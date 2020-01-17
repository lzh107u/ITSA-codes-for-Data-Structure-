#include<stdio.h>
#include<stdlib.h>
/*

	�D�ءG��J N �� ( 1 <= N <= 7 ) �Ʀr��A��X�o�ǼƦr�� " �̤j�ƦC�ƦC - �̤p�ƦC�ƦC "
	
	�L�{�G
		�����ŧi input[ 1024 ] ��Ū�J�r�� gets( input ) ���x�s�B					-	( 1 ) 
		�ŧi origin[ 10 ] ���x�s�L�o�X���Ʀr�A�å��� ' N ' �@����l�� 			-	( 2 ) 
		���ۥ� while(  ) �ӧP�w�X�Ʀr�ö�J origin[ 10 ]�G							-	( 3 ) 
			��X����G�J��ū��СB�J�쵲���Ÿ��B�J�촫��
			�Y�P�w��e��m���Ʀr ( *ptr >= 48 && *ptr <= 57 ) �A�h��J origin[ ... ]
			������Acounter �Y��Ū�J���Ʀr�Ӽ�
		
		�b min process ���G															-	( 4 ) 
			�� bubble sort �N origin[ ... ] ������ƥѤp�ƨ�j
			�N ptr ���V origin[ ... ] �}�C�}�Y
			�A�H min = atoi( ptr ) �A�N min �]���̤p�ƦC��
			
		�b max process ���G															-	( 5 ) 
			�� bubble sort �N origin[ ... ] ������ƥѤj�ƨ�p
			�N ptr ���V origin[ ... ] �}�C�}�Y
			�A�H max = atoi( ptr ) �A�N max �]���̤j�ƦC��
			
		�̫�� printf("%d\n", max - min ) �N���צL�X 								-	( 6 ) 

*/
int main()
{
	char input[ 1024 ], origin[ 10 ], compare;
	char* ptr = NULL;
	int max, min, tmp, l1, l2, l3, counter = 0;
	
	ptr = &input[ 0 ];
	
	for( l1 = 0; l1 < 10; l1++ )												//	->	( 2 ) 
	{
		origin[ l1 ] = 'N';
	}
	
	gets( input );																//	->	( 1 ) 
	while( ptr != NULL && *ptr != EOF && *ptr != '\0' && *ptr != '\n' )			//	->	( 3 ) 
	{
		if( *ptr >= 48 && *ptr <= 57 )
		{
			origin[ counter ] = *ptr;
			counter++;
		}
		ptr++;
	}
	
	//	min process		
	
	for( l1 = 0; l1 < counter - 1; l1++ )										//	->	( 4 ) 
	{
		for( l2 = 0; l2 < counter - 1 - l1; l2++ )
		{
			if( origin[ l2 ] > origin[ l2 + 1 ] )
			{
				tmp = origin[ l2 ];
				origin[ l2 ] = origin[ l2 + 1 ];
				origin[ l2 + 1 ] = tmp;
			}
		}
	}
	ptr = &origin[ 0 ];
	min = atoi( ptr );
	
	//	max process
	
	for( l1 = 0; l1 < counter - 1; l1++ )										//	->	( 5 ) 
	{
		for( l2 = 0; l2 < counter - 1 - l1; l2++ )
		{
			if( origin[ l2 ] < origin[ l2 + 1 ] )
			{
				tmp = origin[ l2 ];
				origin[ l2 ] = origin[ l2 + 1 ];
				origin[ l2 + 1 ] = tmp;
			}
		}
	}
	ptr = &origin[ 0 ];
	max = atoi( ptr );
	
	printf("%d\n", max - min );													//	-> ( 6 ) 
	return 0;
}
