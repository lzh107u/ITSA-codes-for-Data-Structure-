#include<stdio.h>
#include<stdlib.h>
/*

	�D�ءG	������J�@�Ӿ�ơA��ܦ��X�D�F�A��J�j�x�} row, column�� �� �p��}���j�p�A�̫��J�j�x�}���U����
			��X�j�x�}���A�����`�M�̤j���p��}���`�M 
	
	�L�{�G
		�ŧi line[ 1024 ] ������ƪ�Ū�J�B
		Ū�J num_picture �@���D��										-	( 1 )
		
		�b���� num_picture ���� for �j�餤�G							-	( 2 )
			Ū�J row �ò��L���۪��Ʀr�P���ť�							-	( 3 )
			Ū�J column �ò��L���۪��Ʀr�P���ť�						-	( 4 )
			Ū�J size ��@�p�x�}���j�p									-	( 5 )
		
			�ھ�Ū�쪺 row, column �ӫŧi�Ŷ�							-	( 6 )
			�� gets( line ) Ū�J���									-	( 7 )
			�b while() ��												-	( 8 )
				�Y Ū��Ʀr												-	( 9 )
					���L���Ʀr�Ϊť�
				�Y Ū�� " - "											-	( 10 )
					�N�᭱���ƦrŪ�J�Ფ�L���Ʀr�Ϊť�
				��L													-	( 11 )
					�������L���U�@��
			
			Ū�J������}�l���y											-	( 12 )
			�Υ|�h for() ���O���� �jrow�B�jcolumn�B�prow�B�pcolumn
			��� sum_tmp �P sum ���j�p									-	( 13 )
				�Y sum_tmp > sum �� sum == 0
					�N��s
			
			�L�X�o�D�����G ( sum ) 

*/
int main()
{
	char line[ 1024 ];
	char* ptr = NULL;
	int** matrix = NULL;
	int num_picture, l1, l2, l3, l4, l5, row, column, size;
	int sum_tmp, sum;
	
	gets( line );
	ptr = &line[ 0 ];
	num_picture = atoi( ptr );													//	->	( 1 )
	
	for( l1 = 0; l1 < num_picture; l1++ )										//	->	( 2 )
	{
		gets( line );
		ptr = &line[ 0 ];
		row = atoi( ptr );														//	->	( 3 )
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		column = atoi( ptr );													//	->	( 4 )
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		size = atoi( ptr );														//	->	( 5 )
//		printf("row: %d, column: %d, size: %d\n", row, column, size );
		matrix = ( int** )malloc( sizeof( int* )*row );							//	->	( 6 )
		for( l2 = 0; l2 < row; l2++ )
		{
			matrix[ l2 ] = ( int* )malloc( sizeof( int )*column );
			
			gets( line );
			
			ptr = &line[ 0 ];													//	->	( 7 )
			l3 = 0;
			while( ptr != NULL && *ptr != '\0' && *ptr != '\n' && *ptr != EOF )	//	->	( 8 )
			{
				if( *ptr == 45 )												//	->	( 10 )
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
				else if( *ptr >= 48 && *ptr <= 57 )								//	->	( 9 )
				{
					matrix[ l2 ][ l3 ] = atoi( ptr );
					l3++;
					while( *ptr >= 48 && *ptr <= 57 )
					{
						ptr++;
					}
				}
				else															//	->	( 11 )
				{
					ptr++;
				}
			}
		}
		
		sum = 0;
		for( l2 = 0; l2 < row - size + 1; l2++ )								//	->	( 12 )
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
				if( sum_tmp > sum || sum == 0 )									//	->	( 13 )
				{
					sum = sum_tmp;
				}
			}
		}
		printf("%d\n", sum );
		
		free( matrix );
	}
	
	
	
	return 0;
}
