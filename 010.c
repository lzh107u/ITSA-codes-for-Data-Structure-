#include<stdio.h>
#include<stdlib.h>
/*
	
	�D�ءG ��J �믲�O��� �� �q�ܮɼ�( �H����� ) �A��X�q�ܶO
	
	�L�{�G
		�����ŧi input[ 1024 ] �Ω�Ū�J���												-	( 1 )
			���N���Ы��V�Ĥ@��å� option = atoi( ptr ) �N�믲���Ū�J					-	( 2 )		
			�A���L��L�Ʀr�������A�]�� atoi �|����Ū�J���Ʀr�A�]�����Ʀr�|�y���~�P	-	( 3 )
			���ۦA���L�D�Ʀr������														-	( 4 )
			�I��ĤG�ӼƦr��A�A�� time_int = atoi( ptr ) �N�ɼ�Ū�J					-	( 5 )
			
		���ۥ��P�_�믲��סA�A�P�_�����O�_�W�L�믲�O									-	( 6 )
			�W�L�믲�O�@���H�W�P�_�A�M�w�馩���T��
			�o�̥� time_float*rate > option_float �Ӱ��P�w
				�Y �ɼ�( float ���A ) �P �O�v ( rate ) �ۭ���j��믲�O
					�h�A�θ��j���馩
				�Y �_
					�h�A�θ��p���馩
		
		�o�X���׫�A�|�ˤ��J															-	(7 )
		���N answer_int �@�� answer_float ���L����˥h���G
		�A�N tmp �]�� ( float )answer_int
		�h answer_float - tmp �N�O�ѤU���p�Ƴ���
			�Y �ѤU�������j�󵥩� 0.5
				�h answer_int++
			�Y �_ 
				�h answer_int ����
		
		�̫�L�X answer_int 
	
*/
int main()
{
	char input[ 1024 ];						//	->	( 1 )
	gets( input );
	
	char* ptr = NULL;
	int option, time_int, answer_int;
	float time_float, option_float, rate, discount, answer_float, tmp;
	
	ptr = &input[ 0 ];
	option = atoi( ptr );					//	->	( 2 )
	while( *ptr >= 48 && *ptr <= 57 )		//	->	( 3 )
	{
		ptr++;
	}
	while( *ptr < 48 || *ptr > 57 )			//	->	(  4 )
	{
		ptr++;
	}
	time_int = atoi( ptr );					//	->	( 5 )
	
	time_float = ( float )time_int;
	option_float = ( float )option;
	
	if( option == 186 ) 					//	->	( 6 )
	{
		rate = 0.09;
		if( time_float*rate > option_float )
		{
			discount = 0.8;
		}
		else
		{
			discount = 0.9;
		}
	}
	else if( option == 386 )
	{
		rate = 0.08;
		if( time_float*rate > option_float )
		{
			discount = 0.7;
		}
		else
		{
			discount = 0.8;
		}
	}
	else if( option == 586 )
	{
		rate = 0.07;
		if( time_float*rate > option_float )
		{
			discount = 0.6;
		}
		else
		{
			discount = 0.7;
		}
	}
	else if( option == 986 )
	{
		rate = 0.06;
		if( time_float*rate > option_float )
		{
			discount = 0.5;
		}
		else
		{
			discount = 0.6;
		}
	}
	answer_float = time_float * rate * discount;
	
	answer_int = ( int )answer_float;		//	->	( 7 )
	tmp = ( float )answer_int;
	
	if( answer_float - tmp >= 0.5 )
	{
		answer_int = answer_int + 1;
	}
	if( answer_int < option )
	{
		answer_int = option;
	}
	
	printf("%d\n", answer_int );
	return 0;
} 
