#include<stdio.h>
#include<stdlib.h>
/*
	�D�ءG��J�@�ӼƿW ( 9*9 int��} )�A�P�w�O�_�O�ӫ��ӳW�h��g�����T�ƿW
	
	�L�{�G
		�ƿW�j�P�W�h�G
			�C�@�� 1~9 ������
			�C�@�C 1~9 ������
			�C�@ 3*3 ��} 1~9 ������
		
		�����ŧi matrix[ 9 ][ 9 ] ���x�s��J���																-	( 1 ) 
		�� gets( line ) ��Ū�J����A�C�J��@�ӼƦr ( *ptr >= 48 && *ptr <= 57 ) �N��J matrix ��				-	( 2 ) 
		
		���ۥѤT�j�W�h�Ӷi��T���P�w�G
			�C row ������																						-	( 3 ) 
			�C column ������																					-	( 4 ) 
			�C 3*3 ��}������																					-	( 5 ) 
		�C�@���P�w�ɳ��ϥ� list_check[ 9 ] �i��P�w�G
			�Y list_check[ matrix[ row ][ column ] ] == 0 �h��ܥ���L�A�N��אּ 1
			�Y list_check[ matrix[ row ][ column ] ] == 1 �h��ܤw��L�A�L�X���G��N change �]�� 1 �� break
			�ѩ�ƿW�Ȧ� 1~9 �A�Y�� 0 �h��ܸӮ楼��J�A�B�Ӯ椣�i�J�P�_�{��
			
		�᳣̫�]����A�Y change == 0 �A�h�L�X true ��ܿ�J���ƿW�ŦX�W�h 										-	( 6 ) 
		 
*/
int main()
{
	char line[ 1024 ];
	int matrix[ 9 ][ 9 ];
	int sqr_row, sqr_column, sqr_flag, change = 0;
	int l1, l2, l3, l4;
	int list_check[ 9 ];
	
	char* ptr = NULL;
	for( l1 = 0; l1 < 9; l1 ++ )											//	->	( 1 ) 
	{
		gets( line );
		ptr = &line[ 0 ];
		l2 = 0;
		while( ptr != NULL && *ptr != '\0' && *ptr != EOF && *ptr != '\n' )	//	->	( 2 )
		{
			if( *ptr >= 48 && *ptr <= 57 )
			{
				matrix[ l1 ][ l2 ] = *ptr - 48;
				l2++;
			}
			if( l2 >= 9 )
			{
				break;
			}
			ptr++;
		}
	}
	
	for( l1 = 0; l1 < 9; l1++ )												//	->	( 3 )
	{
		for( l2 = 0; l2 < 9; l2++ )
		{
			list_check[ l2 ] = 0;
		}
		for( l2 = 0; l2 < 9; l2++ )
		{
			if( matrix[ l1 ][ l2 ] != 0 )
			{
				if( list_check[ matrix[ l1 ][ l2 ] - 1 ] == 0 )
				{
					list_check[ matrix[ l1 ][ l2 ] - 1 ] = 1;
				}
				else if( list_check[ matrix[ l1 ][ l2 ] - 1 ] == 1 )
				{
					printf("row%d #%d\n", l1 + 1, matrix[ l1 ][ l2 ] );
					change = 1;
					break;
				}
			}

		}
	}
	for( l1 = 0; l1 < 9; l1++ )												//	->	( 4 )
	{
		for( l2 = 0; l2 < 9; l2++ )
		{
			list_check[ l2 ] = 0;
		}
		for( l2 = 0; l2 < 9; l2++ )
		{
			if( matrix[ l2 ][ l1 ] != 0 )
			{
				if( list_check[ matrix[ l2 ][ l1 ] - 1 ] == 0 )
				{
					list_check[ matrix[ l2 ][ l1 ] - 1 ] = 1;
				}
				else if( list_check[ matrix[ l2 ][ l1 ] - 1 ] == 1 )
				{
					printf("column%d #%d\n", l1 + 1, matrix[ l2 ][ l1 ] );
					change = 1;
					break;
				}
			}
		}
	}
	for( l1 = 0; l1 < 3; l1++ )												//	->	( 5 )
	{
		for( l2 = 0; l2 < 3; l2++ )						//	��e������m�� matrix[ l1*3 + l3 ][ l2*3 + l4 ]
		{
			for( l3 = 0; l3 < 9; l3++ )
			{
				list_check[ l3 ] = 0;
			}
			for( l3 = 0; l3 < 3; l3++ )
			{
				sqr_flag = 0;
				sqr_row = l1*3 + l3;
				for( l4= 0; l4 < 3; l4++ )
				{
					sqr_column = l2*3 + l4;
					if( matrix[ sqr_row ][ sqr_column ] != 0 )
					{
						if( list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] == 0 )
						{
							list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] = 1;
						}
						else if( list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] == 1 )
						{
							printf("block%d #%d\n", l1*3 + l2 + 1, matrix[ sqr_row ][ sqr_column ] );
							change = 1;
							sqr_flag = 1;
							break;
						}
					}
				}
				if( sqr_flag == 1 )
				{
					break;
				}
			}
		}
	}
	if( change == 0 )
	{
		printf("true\n");
	}
	return 0;
}
