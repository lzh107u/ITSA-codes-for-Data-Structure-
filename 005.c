#include<stdio.h>
#include<stdlib.h>
/*

	�D�ءG��J n �����ȭq��A�����o���ɶ� s �M��^�ɶ� d �C�Y�ɬq�Ĭ�A�h�ݭn�h���@�x���F�u�n�ɶ����Ĭ�A�P�@�����N�i�H�~��X���ȡC 

	�L�{�G
		������ gets( line ) Ū�J�r��A�� ptr ���V line ���Ĥ@��
		�� num_work = atoi( ptr ) �N num_work �]�����ȭq��ƶq n 
		�ŧi time ( int** ) �ӷ�@�԰Ȯɶ���A�j�p�� time[ num_work ][ 24 ] �ê�l�ơG											-	( 1 ) 
			�� num_work �O�]���̦h�N�O�n�o��h�x�� 
			�� 24 �O�N��ѤƧ@ 24 �Ӯɬq�A�C�@��s�����_�l�ɶ�( �p time[ 2 ][ 12 ] �� 2 ���� 1200 ~ 1300 ���ɬq )
			�Y�Ӯɬq�X�Ԥ��A�O�� 1 �F�Ϥ��h�� 0
		 
		�A�� while( ) Ū�J�_�l�P�����ɶ� ( list_work[ ... ][ 0 ]: �_�l�ɶ��F list_work[ ... ][ 1 ]: �פ�ɶ� )�G 				-	( 2 )
			��X���� ( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' ) 
				ptr �����ū��СB*ptr ��������B*ptr ���������Ÿ��B*ptr���������Ÿ�
			�Y�J��Ʀr ( *ptr <= 57 && *ptr >= 48 ) �h�� atoi( ptr ) Ū�J�Ʀr�@���_�l�ɶ� ( 48 ~ 57 �� 0 ~ 9 �� ASCII code )	-	( 3 ) 
			��J��A ptr �����ť� ( ASCII code: 32 ) �A���ۦA���L�ť�															-	( 4 ) 
			�AŪ�J�Ʀr�@�������ɶ�																								-	( 5 )
		
		���ۥ����h for �j��h���y�C�@�������԰Ȫ�( time )�A�Y�԰Ȫ�W�i�H��U��e�����ȡA�h��ʫ� break 						-	( 6 )
		
		�̫�A���y�@���԰Ȫ� ( time )�A�Y���� 1 �A�h num_bus++ �� break �h���U�@�x�����԰Ȫ�									-	( 7 )
			���즳�@�x���O�� 0 �A�h���A�O num_bus 
								  
*/
int main()
{
	int num_work, l1, l2, l3, start, end, flag, num_bus = 0;
	char line[ 1024 ];
	char* ptr = NULL;
	int** time = NULL;
	gets( line );
	ptr = &line[ 0 ];
	num_work = atoi( ptr );

	time = ( int** )malloc( sizeof( int* )*num_work );
	for( l1 = 0; l1 < num_work; l1++ )									//	->	( 1 )
	{
		time[ l1 ] = ( int* )malloc( sizeof( int )*24 );
		for( l2 = 0; l2 < 24; l2++ )
		{
			time[ l1 ][ l2 ] = 0;
		}
	}
	int list_work[ num_work ][ 2 ];
	gets( line );
	ptr = &line[ 0 ];
	l1 = 0;
	while( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' )	//	->	( 2 )
	{
		if( *ptr <= 57 && *ptr >= 48 )									//	->	( 3 )
		{
			list_work[ l1 ][ 0 ] = atoi( ptr );
		}
		while( *ptr <= 57 && *ptr >= 48 )								//	->	( 4 )
		{
			ptr++;
		}
		ptr++;
		if( *ptr <= 57 && *ptr >= 48 )									//	->	( 5 )
		{
			list_work[ l1 ][ 1 ] = atoi( ptr );							
			l1++;
		}
		while( *ptr <= 57 && *ptr >= 48 )
		{
			ptr++;
		}
		ptr++;
	}
	for( l1 = 0; l1 < num_work; l1++ )									//	->	( 6 )
	{
		start = list_work[ l1 ][ 0 ];
		end = list_work[ l1 ][ 1 ];
		
		for( l2 = 0; l2 < num_work; l2++ )
		{
			flag = 0;
			for( l3 = start; l3 < end; l3++ )
			{
				if( time[ l2 ][ l3 ] == 0 )
				{
					flag = 0;
				}
				else if( time[ l2 ][ l3 ] == 1 )	//	��e�ɬq�X�Ԥ�	->	���U�@�x 
				{
					flag = 1;
					break;
				}
			}
			if( flag == 1 )
			{
				flag = 0;
			}
			else if( flag == 0 )
			{
				for( l3 = start; l3 < end; l3++ )
				{
					time[ l2 ][ l3 ] = 1;
				}
				break;
			}
		}
	}
	for( l1 = 0; l1 < num_work; l1++ )									//	->	( 7 ) 
	{
		flag = 0;
		for( l2 = 0; l2 < 24; l2++ )
		{
			if( time[ l1 ][ l2 ] == 1 )
			{
				num_bus++;
				flag = 1;
				break;
			}
		}
		if( flag == 0 )
		{
			break;
		}
	}
	printf("%d\n", num_bus );
	
	return 0;	
} 
