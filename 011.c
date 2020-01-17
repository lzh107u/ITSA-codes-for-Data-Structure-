#include<stdio.h>
#include<stdlib.h>
/*

	題目：	首先輸入一個整數，表示有幾題；再輸入大矩陣 row, column數 及 小方陣的大小，最後輸入大矩陣中各元素
			輸出大矩陣中，元素總和最大的小方陣之總和 
	
	過程：
		宣告 line[ 1024 ] 做為資料的讀入處
		讀入 num_picture 作為題數										-	( 1 )
		
		在執行 num_picture 次的 for 迴圈中：							-	( 2 )
			讀入 row 並略過接著的數字與後方空白							-	( 3 )
			讀入 column 並略過接著的數字與後方空白						-	( 4 )
			讀入 size 當作小矩陣的大小									-	( 5 )
		
			根據讀到的 row, column 來宣告空間							-	( 6 )
			由 gets( line ) 讀入資料									-	( 7 )
			在 while() 中												-	( 8 )
				若 讀到數字												-	( 9 )
					略過後方數字及空白
				若 讀到 " - "											-	( 10 )
					將後面的數字讀入後略過後方數字及空白
				其他													-	( 11 )
					直接略過換下一個
			
			讀入結束後開始掃描											-	( 12 )
			用四層 for() 分別控制 大row、大column、小row、小column
			比較 sum_tmp 與 sum 的大小									-	( 13 )
				若 sum_tmp > sum 或 sum == 0
					就更新
			
			印出這題的結果 ( sum ) 

*/
int main()
{
	char line[ 1024 ];
	char* ptr = NULL;
	int** matrix = NULL;
	int num_picture, l1, l2, l3, l4, l5, row, column, size;
	int sum_tmp, sum;
	
	gets( line );
	ptr = &line[ 0 ];
	num_picture = atoi( ptr );													//	->	( 1 )
	
	for( l1 = 0; l1 < num_picture; l1++ )										//	->	( 2 )
	{
		gets( line );
		ptr = &line[ 0 ];
		row = atoi( ptr );														//	->	( 3 )
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		column = atoi( ptr );													//	->	( 4 )
		while( *ptr >= 48 && *ptr <= 57 )
		{
			ptr++;
		}
		ptr++;
		size = atoi( ptr );														//	->	( 5 )
//		printf("row: %d, column: %d, size: %d\n", row, column, size );
		matrix = ( int** )malloc( sizeof( int* )*row );							//	->	( 6 )
		for( l2 = 0; l2 < row; l2++ )
		{
			matrix[ l2 ] = ( int* )malloc( sizeof( int )*column );
			
			gets( line );
			
			ptr = &line[ 0 ];													//	->	( 7 )
			l3 = 0;
			while( ptr != NULL && *ptr != '\0' && *ptr != '\n' && *ptr != EOF )	//	->	( 8 )
			{
				if( *ptr == 45 )												//	->	( 10 )
				{
					ptr++;
					matrix[ l2 ][ l3 ] = atoi( ptr );
					matrix[ l2 ][ l3 ] = -1 * matrix[ l2 ][ l3 ];
					l3++;
					while( *ptr >= 48 && *ptr <= 57 )
					{
						ptr++;
					}
				}
				else if( *ptr >= 48 && *ptr <= 57 )								//	->	( 9 )
				{
					matrix[ l2 ][ l3 ] = atoi( ptr );
					l3++;
					while( *ptr >= 48 && *ptr <= 57 )
					{
						ptr++;
					}
				}
				else															//	->	( 11 )
				{
					ptr++;
				}
			}
		}
		
		sum = 0;
		for( l2 = 0; l2 < row - size + 1; l2++ )								//	->	( 12 )
		{
			for( l3 = 0; l3 < column - size + 1; l3++ )
			{
				sum_tmp = 0;
				
				for( l4 = 0; l4 < size; l4++ )
				{
					for( l5 = 0; l5 < size; l5++ )
					{
						sum_tmp = sum_tmp + matrix[ l2 + l4 ][ l3 + l5 ];
					}
				}
				if( sum_tmp > sum || sum == 0 )									//	->	( 13 )
				{
					sum = sum_tmp;
				}
			}
		}
		printf("%d\n", sum );
		
		free( matrix );
	}
	
	
	
	return 0;
}
