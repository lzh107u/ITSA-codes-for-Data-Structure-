#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*

	�D�ءG	��o���AŪ�J�@�� 8 ��ƯS�O�����X�A�ΤT�� 8 ��Ƹ��X
			�Y	�P�S�O�����X�����۲šA������ʸU��
			�Y	�P�t�T�ո��X�����۲šA�����G�Q�U��
			�Y	�P�t�T�ո��X�� 7 �X�۲šA�����|�U��
			�Y	�P�t�T�ո��X�� 6 �X�۲šA�����@�U��
			�Y	�P�t�T�ո��X�� 5 �X�۲šA�����|�d��
			�Y	�P�t�T�ո��X�� 4 �X�۲šA�����@�d��
			�Y	�P�t�T�ո��X�� 3 �X�۲šA������ʤ� 
			
			Ū�J N �i�o�����X��A��X�U�ؼ������o���ƶq���`���� 
			
	�L�{�G
		�ŧi line[ 1024 ] �@�����Ū�J�B
		�ŧi list[ 4 ][ 15 ] �@��������X�x�s�B
		�ŧi prize[ 7 ] �@���U�����ƶq�p�ƾ�
		
		Ū�J num_ticket �@���ݹ���o�����ƶq				-	( 1 ) 
		�b���� num_ticket ���� for(  ) ���G					-	( 2 ) 
			Ū�J��e���X									-	( 3 ) 
			�Y	��e���X�P�S�O���۲�						-	( 4 ) 
				prize[ 0 ]++ ( �S�O���ƶq + 1 )				
			�Y	�_											-	( 5 ) 
				�q�Ĥ@�մ��q�����X�}�l��G					-	( 6 ) 
					�q�̫᭱�}�l����A�@�o�{���P�Y���X		-	( 7 ) 
					counter �b l3 <= 5 �����p�U�|�}�l����	-	( 8	)
						��� l5 �ɡA�~���ܤ֤T�ӼƦr�ۦP 
					��X��A counter �N�O��o������			
						prize[ counter ]++					-	( 9 )
		
		�L�X�U�������ƶq									-	( 10 )
		 
		��̫�[�`�U�����ƶq�ûP����������ƶq�ۭ� 			-	( 11 )
		  
*/
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
	num_ticket = atoi( ptr );								//	->	( 1 )
	for( l1 = 0; l1 < 7; l1++ )
	{
		prize[ l1 ] = 0;
	}
	sum = 0;
	
	for( l1 = 0; l1 < num_ticket; l1++ )					//	->	( 2 )
	{
		gets( line );										//	->	( 3 )
		line[ 8 ] = '\0';
		if( strcmp( line, list[ 0 ] ) == 0 )				//	->	( 4 )
		{
			prize[ 0 ]++;
		}
		else												//	->	( 5 )
		{
			for( l2 = 1; l2 < 4; l2++ )						//	->	( 6 )
			{
				counter = 7;
				for( l3 = 7; l3 >= 0; l3-- )				//	->	( 7 )
				{
					if( line[ l3 ] == list[ l2 ][ l3 ] )
					{
						if( l3 <= 5 )						//	->	( 8 )
						{
							counter--;
						}
					}
					else
					{
						break;
					}
				}
				if( counter < 7 )							//	->	( 9 )
				{
					prize[ counter ]++;
					break;
				}
			}
		}
	}
															//	->	( 11 )
	sum = prize[ 0 ]*2000000 + prize[ 1 ]*200000 + prize[ 2 ]*40000 + prize[ 3 ]*10000 + prize[ 4 ]*4000 + prize[ 5 ]*1000 + prize[ 6 ]*200;
	
	for( l1 = 0; l1 < 7; l1++ )								//	->	( 10 )
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
