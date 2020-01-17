#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*

	題目：	對發票，讀入一組 8 位數特別獎號碼，及三組 8 位數號碼
			若	與特別獎號碼完全相符，獎金兩百萬元
			若	與另三組號碼完全相符，獎金二十萬元
			若	與另三組號碼末 7 碼相符，獎金四萬元
			若	與另三組號碼末 6 碼相符，獎金一萬元
			若	與另三組號碼末 5 碼相符，獎金四千元
			若	與另三組號碼末 4 碼相符，獎金一千元
			若	與另三組號碼末 3 碼相符，獎金兩百元 
			
			讀入 N 張發票號碼後，輸出各種獎項的得獎數量及總獎金 
			
	過程：
		宣告 line[ 1024 ] 作為資料讀入處
		宣告 list[ 4 ][ 15 ] 作為對獎號碼儲存處
		宣告 prize[ 7 ] 作為各獎項數量計數器
		
		讀入 num_ticket 作為待對獎發票的數量				-	( 1 ) 
		在執行 num_ticket 次的 for(  ) 中：					-	( 2 ) 
			讀入當前號碼									-	( 3 ) 
			若	當前號碼與特別獎相符						-	( 4 ) 
				prize[ 0 ]++ ( 特別獎數量 + 1 )				
			若	否											-	( 5 ) 
				從第一組普通獎號碼開始對：					-	( 6 ) 
					從最後面開始比較，一發現不同即跳出		-	( 7 ) 
					counter 在 l3 <= 5 的情況下會開始遞減	-	( 8	)
						比到 l5 時，才有至少三個數字相同 
					脫出後， counter 就是獲得的獎項			
						prize[ counter ]++					-	( 9 )
		
		印出各獎項的數量									-	( 10 )
		 
		於最後加總各項的數量並與其對應獎金數量相乘 			-	( 11 )
		  
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
