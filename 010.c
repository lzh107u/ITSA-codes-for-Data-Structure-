#include<stdio.h>
#include<stdlib.h>
/*
	
	題目： 輸入 月租費方案 及 通話時數( 以秒為單位 ) ，輸出電話費
	
	過程：
		首先宣告 input[ 1024 ] 用於讀入資料												-	( 1 )
			先將指標指向第一格並由 option = atoi( ptr ) 將月租方案讀入					-	( 2 )		
			再跳過其他數字的部分，因為 atoi 會直接讀入整串數字，因此後方數字會造成誤判	-	( 3 )
			接著再跳過非數字的部分														-	( 4 )
			碰到第二個數字後，再由 time_int = atoi( ptr ) 將時數讀入					-	( 5 )
			
		接著先判斷月租方案，再判斷價錢是否超過月租費									-	( 6 )
			超過月租費一倍以上與否，決定折扣的幅度
			這裡用 time_float*rate > option_float 來做判定
				若 時數( float 型態 ) 與 費率 ( rate ) 相乘後大於月租費
					則適用較大的折扣
				若 否
					則適用較小的折扣
		
		得出答案後再四捨五入															-	(7 )
		先將 answer_int 作為 answer_float 的無條件捨去結果
		再將 tmp 設為 ( float )answer_int
		則 answer_float - tmp 就是剩下的小數部分
			若 剩下的部分大於等於 0.5
				則 answer_int++
			若 否 
				則 answer_int 不動
		
		最後印出 answer_int 
	
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
