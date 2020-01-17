#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	
	題目：	輸入由 0 1 組成之圖形， 0 1 之交界輸出 "0 "；非交界則輸出 "_ "
	
	過程：	首先宣告 data[ 105 ][ 105 ] 來儲存資料
			讀入 num_picture 來決定有幾張圖要處理 
			 
			首先由 gets( input ) 讀入資料
			再透過 ptr 從 input[ 0 ] 開始向後檢查
			
			第一格必是 num_row，因此將用 num_row = atoi( ptr ); 將資料從 char 變成 int 並存給 num_row 	-	( 1 )
			接著 while 迴圈，透過其條件( *ptr >= 48 && *ptr <= 57 )來略過數字( 透過 ASCII碼判定 )		-	( 2 )
			再由下一個 while 迴圈，透過其條件( *ptr == 32 )來略過空白									-	( 3 )
			因此下一個數字就是 num_column，使用 num_column = atoi( ptr );								-	( 4 )
			
			接下來進入讀入 + 處理階段
			首先執行 num_row * num_column 次( 兩層迴圈 )，將資料讀進 data[ ... ][ ... ]
			再用幾個 case 去判定：
			若為 0 										-	( 5 )
				->	直接輸出 "_ "
			若為 1										-	( 6 )
				->	檢查左右，若左側為 0 or 右側為 0 
					->	輸出 "0 " 
				->	檢查上下，若上方為 0 or 下方為 0
					->	輸出 "0 "
				->	若皆無 0
					->	輸出"_ "
	 
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
				if( *ptr == 48 )		//	48 為 0 的 ASCII code 
				{
					data[ l2 ][ l3 ] = 0;
					l3++;
				}
				else if( *ptr == 49 )	//	49 為 1 的 ASCII code 
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
					if( l3 > 0 )			//	若 data[ l2 ][ l3 ] 不是最左邊一行，檢查左側元素 
					{
						if( data[ l2 ][ l3-1 ] == 0 )
						{
							flag = 1;
						}
					}
					if( l3 < num_column-1 )	//	若 data[ l2 ][ l3 ] 不是最右邊一行，檢查右側元素 
					{
						if( data[ l2 ][ l3+1 ] == 0 )
						{
							flag = 1;
						}
					}
					// above and under
					if( l2 > 0 )			//	若 data [ l2 ][ l3 ] 不是最上面一列，檢查上方元素 
					{
						if( data[ l2-1 ][ l3 ] == 0 )	 
						{
							flag = 1;
						}
					}
					if( l2 < num_row-1 )	//	若 data[ l2 ][ l3 ] 不是最下面一列，檢查下方元素 
					{
						if( data[ l2+1 ][ l3 ] == 0 )
						{
							flag = 1;
						}
					}
					if( flag == 1 )		//	若在上述檢查中找到 0，則印出邊界結果 "0 " 
					{
						printf("0 ");
					}
					else				//	若否，則印出非邊界結果 "_ " 
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
