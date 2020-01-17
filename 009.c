#include<stdio.h>
#include<stdlib.h>
/*

	題目：輸入 N 個 ( 1 <= N <= 7 ) 數字後，輸出這些數字的 " 最大排列數列 - 最小排列數列 "
	
	過程：
		首先宣告 input[ 1024 ] 為讀入字串 gets( input ) 的儲存處					-	( 1 ) 
		宣告 origin[ 10 ] 來儲存過濾出的數字，並先填滿 ' N ' 作為初始化 			-	( 2 ) 
		接著用 while(  ) 來判定出數字並填入 origin[ 10 ]：							-	( 3 ) 
			脫出條件：遇到空指標、遇到結尾符號、遇到換行
			若判定當前位置為數字 ( *ptr >= 48 && *ptr <= 57 ) ，則填入 origin[ ... ]
			結束後，counter 即為讀入的數字個數
		
		在 min process 中：															-	( 4 ) 
			用 bubble sort 將 origin[ ... ] 中的資料由小排到大
			將 ptr 指向 origin[ ... ] 陣列開頭
			再以 min = atoi( ptr ) ，將 min 設為最小排列數
			
		在 max process 中：															-	( 5 ) 
			用 bubble sort 將 origin[ ... ] 中的資料由大排到小
			將 ptr 指向 origin[ ... ] 陣列開頭
			再以 max = atoi( ptr ) ，將 max 設為最大排列數
			
		最後用 printf("%d\n", max - min ) 將答案印出 								-	( 6 ) 

*/
int main()
{
	char input[ 1024 ], origin[ 10 ], compare;
	char* ptr = NULL;
	int max, min, tmp, l1, l2, l3, counter = 0;
	
	ptr = &input[ 0 ];
	
	for( l1 = 0; l1 < 10; l1++ )												//	->	( 2 ) 
	{
		origin[ l1 ] = 'N';
	}
	
	gets( input );																//	->	( 1 ) 
	while( ptr != NULL && *ptr != EOF && *ptr != '\0' && *ptr != '\n' )			//	->	( 3 ) 
	{
		if( *ptr >= 48 && *ptr <= 57 )
		{
			origin[ counter ] = *ptr;
			counter++;
		}
		ptr++;
	}
	
	//	min process		
	
	for( l1 = 0; l1 < counter - 1; l1++ )										//	->	( 4 ) 
	{
		for( l2 = 0; l2 < counter - 1 - l1; l2++ )
		{
			if( origin[ l2 ] > origin[ l2 + 1 ] )
			{
				tmp = origin[ l2 ];
				origin[ l2 ] = origin[ l2 + 1 ];
				origin[ l2 + 1 ] = tmp;
			}
		}
	}
	ptr = &origin[ 0 ];
	min = atoi( ptr );
	
	//	max process
	
	for( l1 = 0; l1 < counter - 1; l1++ )										//	->	( 5 ) 
	{
		for( l2 = 0; l2 < counter - 1 - l1; l2++ )
		{
			if( origin[ l2 ] < origin[ l2 + 1 ] )
			{
				tmp = origin[ l2 ];
				origin[ l2 ] = origin[ l2 + 1 ];
				origin[ l2 + 1 ] = tmp;
			}
		}
	}
	ptr = &origin[ 0 ];
	max = atoi( ptr );
	
	printf("%d\n", max - min );													//	-> ( 6 ) 
	return 0;
}
