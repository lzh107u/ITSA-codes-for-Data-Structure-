#include<stdio.h>
#include<stdlib.h>
/*

	題目： 輸入一排整數，以空格隔開，以相反順序輸出
	
	過程：
		宣告 line[ 1024 ] 作為輸入的暫存處
		宣告 list[ 100 ] 作為數據儲存處
		
		由 while() 迴圈將數據從 line 放進 list：							-	( 1 ) 
			脫出條件：
				若	ptr 為空指標
				若	ptr 為換行
				若	ptr 為結束符號
				若	ptr 為結尾符號 
			若	ptr 為數字 													-	( 2 ) 
				由 list[ counter ] = atoi( ptr ) 將資料讀進 list[ ... ]
				略過後方的數字 
			若	否															-	( 3 ) 
				ptr 指向下一個字
		
		將 list[ ... ] 以相反的順序印出 									-	( 4 ) 

*/
int main()
{
	char line[ 1024 ];
	gets( line );
	
	int list[ 100 ], counter, l1, l2;
	char* ptr = NULL;
	
	ptr = &line[ 0 ];
	counter = 0;
	while( ptr != NULL && *ptr != '\n' && *ptr != EOF && *ptr != '\0' )	//	-> ( 1 ) 
	{
		if( *ptr >= 48 && *ptr <= 57 )									//	->	( 2 ) 
		{
			list[ counter ] = atoi( ptr );
			counter++;
			while( *ptr >= 48 && *ptr <= 57 )
			{
				ptr++;
			}
		}
		else															//	->	( 3 ) 
		{
			ptr++;
		}
	}

	for( l1 = counter-1; l1 >= 0; l1-- )								//	->	( 4 ) 
	{
		if( l1 > 0 )
			printf("%d ", list[ l1 ] );
		else if( l1 == 0 )
			printf("%d\n", list[ l1 ] );
	}
	
	
	return 0;
}
