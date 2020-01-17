#include<stdio.h>
#include<stdlib.h>
int main()
{
	char input[ 1024 ];
	gets( input );
	
	char* ptr = NULL;
	int option, time_int, answer_int;
	float time_float, option_float, rate, discount, answer_float, tmp;
	
	ptr = &input[ 0 ];
	option = atoi( ptr );
	while( *ptr >= 48 && *ptr <= 57 )
	{
		ptr++;
	}
	while( *ptr < 48 || *ptr > 57 )
	{
		ptr++;
	}
	time_int = atoi( ptr );
	
	time_float = ( float )time_int;
	option_float = ( float )option;
	
	if( option == 186 ) 
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
	
	answer_int = ( int )answer_float;
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
