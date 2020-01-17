#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	
	�D�ءG	��J�� 0 1 �զ����ϧΡA 0 1 ����ɿ�X "0 "�F�D��ɫh��X "_ "
	
	�L�{�G	�����ŧi data[ 105 ][ 105 ] ���x�s���
			Ū�J num_picture �ӨM�w���X�i�ϭn�B�z 
			 
			������ gets( input ) Ū�J���
			�A�z�L ptr �q input[ 0 ] �}�l�V���ˬd
			
			�Ĥ@�楲�O num_row�A�]���N�� num_row = atoi( ptr ); �N��Ʊq char �ܦ� int �æs�� num_row 	-	( 1 )
			���� while �j��A�z�L�����( *ptr >= 48 && *ptr <= 57 )�Ӳ��L�Ʀr( �z�L ASCII�X�P�w )		-	( 2 )
			�A�ѤU�@�� while �j��A�z�L�����( *ptr == 32 )�Ӳ��L�ť�									-	( 3 )
			�]���U�@�ӼƦr�N�O num_column�A�ϥ� num_column = atoi( ptr );								-	( 4 )
			
			���U�Ӷi�JŪ�J + �B�z���q
			�������� num_row * num_column ��( ��h�j�� )�A�N���Ū�i data[ ... ][ ... ]
			�A�δX�� case �h�P�w�G
			�Y�� 0 										-	( 5 )
				->	������X "_ "
			�Y�� 1										-	( 6 )
				->	�ˬd���k�A�Y������ 0 or �k���� 0 
					->	��X "0 " 
				->	�ˬd�W�U�A�Y�W�謰 0 or �U�謰 0
					->	��X "0 "
				->	�Y�ҵL 0
					->	��X"_ "
	 
*/
int main()
{
	int num_picture, num_row, num_column, data[ 105 ][ 105 ];
	int l1, l2, l3, flag;
	char input[ 1024 ] = { '\0' };
	char* ptr = NULL; 
	

	gets( input );
	ptr = &input[ 0 ];
	num_picture = atoi( ptr );

	for( l1 = 0; l1 < num_picture; l1++ )
	{
		//	input data
		gets( input );
		ptr = &input[ 0 ];
		num_row = atoi( ptr );				//	( 1 )
		while( *ptr >= 48 && *ptr <= 57 )	//	( 2 )
		{
			ptr++;
		}
		while( *ptr == 32 )					//	( 3 )
		{
			ptr++;
		}
		num_column = atoi( ptr );			//	( 4 )
		
		for( l2 = 0; l2 < num_row; l2++ )
		{	
			gets( input );
			ptr = &input[ 0 ];
			l3 = 0;
			while( *ptr != '\n' && *ptr != '\0' && *ptr != EOF )
			{
				if( *ptr == 48 )		//	48 �� 0 �� ASCII code 
				{
					data[ l2 ][ l3 ] = 0;
					l3++;
				}
				else if( *ptr == 49 )	//	49 �� 1 �� ASCII code 
				{
					data[ l2 ][ l3 ] = 1;
					l3++;
				}
				if( l3 >= num_column )
				{
					break;
				}
				ptr++;
			}
		}
		
		//process data
		for(  l2 = 0; l2 < num_row; l2++ )
		{
			for( l3 = 0; l3 < num_column; l3++ )
			{
				if( data[ l2 ][ l3 ] == 0 )			//	( 5 )
				{
					printf("_ ");
				}
				else if( data[ l2 ][ l3 ] == 1 )	//	( 6 )
				{
					flag = 0;
					//	left and right
					if( l3 > 0 )			//	�Y data[ l2 ][ l3 ] ���O�̥���@��A�ˬd�������� 
					{
						if( data[ l2 ][ l3-1 ] == 0 )
						{
							flag = 1;
						}
					}
					if( l3 < num_column-1 )	//	�Y data[ l2 ][ l3 ] ���O�̥k��@��A�ˬd�k������ 
					{
						if( data[ l2 ][ l3+1 ] == 0 )
						{
							flag = 1;
						}
					}
					// above and under
					if( l2 > 0 )			//	�Y data [ l2 ][ l3 ] ���O�̤W���@�C�A�ˬd�W�褸�� 
					{
						if( data[ l2-1 ][ l3 ] == 0 )	 
						{
							flag = 1;
						}
					}
					if( l2 < num_row-1 )	//	�Y data[ l2 ][ l3 ] ���O�̤U���@�C�A�ˬd�U�褸�� 
					{
						if( data[ l2+1 ][ l3 ] == 0 )
						{
							flag = 1;
						}
					}
					if( flag == 1 )		//	�Y�b�W�z�ˬd����� 0�A�h�L�X��ɵ��G "0 " 
					{
						printf("0 ");
					}
					else				//	�Y�_�A�h�L�X�D��ɵ��G "_ " 
					{
						printf("_ ");
					}
				}
				
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
 } 
