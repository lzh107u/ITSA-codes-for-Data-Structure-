#include<stdio.h>
#include<stdlib.h>
/*

	題目：輸入 n 筆任務訂單，紀載發車時間 s 和返回時間 d 。若時段衝突，則需要多派一台車；只要時間不衝突，同一輛車就可以繼續出任務。 

	過程：
		首先用 gets( line ) 讀入字串，由 ptr 指向 line 的第一格
		由 num_work = atoi( ptr ) 將 num_work 設為任務訂單數量 n 
		宣告 time ( int** ) 來當作勤務時間表，大小為 time[ num_work ][ 24 ] 並初始化：											-	( 1 ) 
			用 num_work 是因為最多就是要這麼多台車 
			用 24 是將整天化作 24 個時段，每一格編號為起始時間( 如 time[ 2 ][ 12 ] 指 2 號車 1200 ~ 1300 的時段 )
			若該時段出勤中，記為 1 ；反之則為 0
		 
		再用 while( ) 讀入起始與結束時間 ( list_work[ ... ][ 0 ]: 起始時間； list_work[ ... ][ 1 ]: 終止時間 )： 				-	( 2 )
			脫出條件 ( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' ) 
				ptr 不為空指標、*ptr 不為換行、*ptr 不為結束符號、*ptr不為結尾符號
			若遇到數字 ( *ptr <= 57 && *ptr >= 48 ) 則由 atoi( ptr ) 讀入數字作為起始時間 ( 48 ~ 57 為 0 ~ 9 的 ASCII code )	-	( 3 ) 
			輸入後， ptr 跳轉到空白 ( ASCII code: 32 ) ，接著再略過空白															-	( 4 ) 
			再讀入數字作為結束時間																								-	( 5 )
		
		接著用雙層 for 迴圈去掃描每一輛車的勤務表( time )，若勤務表上可以塞下當前的任務，則更動後 break 						-	( 6 )
		
		最後再掃描一次勤務表 ( time )，若掃到 1 ，則 num_bus++ 並 break 去掃下一台車的勤務表									-	( 7 )
			直到有一台車是全 0 ，則不再記 num_bus 
								  
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
				else if( time[ l2 ][ l3 ] == 1 )	//	當前時段出勤中	->	換下一台 
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
