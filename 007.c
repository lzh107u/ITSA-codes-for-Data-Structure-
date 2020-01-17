#include<stdio.h>
#include<stdlib.h>
/*
	題目：輸入一個數獨 ( 9*9 int方陣 )，判定是否是個按照規則填寫的正確數獨
	
	過程：
		數獨大致規則：
			每一行 1~9 不重複
			每一列 1~9 不重複
			每一 3*3 方陣 1~9 不重複
		
		首先宣告 matrix[ 9 ][ 9 ] 來儲存輸入資料																-	( 1 ) 
		由 gets( line ) 來讀入測資，每遇到一個數字 ( *ptr >= 48 && *ptr <= 57 ) 就填入 matrix 中				-	( 2 ) 
		
		接著由三大規則來進行三次判定：
			每 row 不重複																						-	( 3 ) 
			每 column 不重複																					-	( 4 ) 
			每 3*3 方陣不重複																					-	( 5 ) 
		每一次判定時都使用 list_check[ 9 ] 進行判定：
			若 list_check[ matrix[ row ][ column ] ] == 0 則表示未填過，將其改為 1
			若 list_check[ matrix[ row ][ column ] ] == 1 則表示已填過，印出結果後將 change 設為 1 並 break
			由於數獨僅有 1~9 ，若為 0 則表示該格未填入，且該格不進入判斷程序
			
		最後都跑完後，若 change == 0 ，則印出 true 表示輸入的數獨符合規則 										-	( 6 ) 
		 
*/
int main()
{
	char line[ 1024 ];
	int matrix[ 9 ][ 9 ];
	int sqr_row, sqr_column, sqr_flag, change = 0;
	int l1, l2, l3, l4;
	int list_check[ 9 ];
	
	char* ptr = NULL;
	for( l1 = 0; l1 < 9; l1 ++ )											//	->	( 1 ) 
	{
		gets( line );
		ptr = &line[ 0 ];
		l2 = 0;
		while( ptr != NULL && *ptr != '\0' && *ptr != EOF && *ptr != '\n' )	//	->	( 2 )
		{
			if( *ptr >= 48 && *ptr <= 57 )
			{
				matrix[ l1 ][ l2 ] = *ptr - 48;
				l2++;
			}
			if( l2 >= 9 )
			{
				break;
			}
			ptr++;
		}
	}
	
	for( l1 = 0; l1 < 9; l1++ )												//	->	( 3 )
	{
		for( l2 = 0; l2 < 9; l2++ )
		{
			list_check[ l2 ] = 0;
		}
		for( l2 = 0; l2 < 9; l2++ )
		{
			if( matrix[ l1 ][ l2 ] != 0 )
			{
				if( list_check[ matrix[ l1 ][ l2 ] - 1 ] == 0 )
				{
					list_check[ matrix[ l1 ][ l2 ] - 1 ] = 1;
				}
				else if( list_check[ matrix[ l1 ][ l2 ] - 1 ] == 1 )
				{
					printf("row%d #%d\n", l1 + 1, matrix[ l1 ][ l2 ] );
					change = 1;
					break;
				}
			}

		}
	}
	for( l1 = 0; l1 < 9; l1++ )												//	->	( 4 )
	{
		for( l2 = 0; l2 < 9; l2++ )
		{
			list_check[ l2 ] = 0;
		}
		for( l2 = 0; l2 < 9; l2++ )
		{
			if( matrix[ l2 ][ l1 ] != 0 )
			{
				if( list_check[ matrix[ l2 ][ l1 ] - 1 ] == 0 )
				{
					list_check[ matrix[ l2 ][ l1 ] - 1 ] = 1;
				}
				else if( list_check[ matrix[ l2 ][ l1 ] - 1 ] == 1 )
				{
					printf("column%d #%d\n", l1 + 1, matrix[ l2 ][ l1 ] );
					change = 1;
					break;
				}
			}
		}
	}
	for( l1 = 0; l1 < 3; l1++ )												//	->	( 5 )
	{
		for( l2 = 0; l2 < 3; l2++ )						//	當前元素位置為 matrix[ l1*3 + l3 ][ l2*3 + l4 ]
		{
			for( l3 = 0; l3 < 9; l3++ )
			{
				list_check[ l3 ] = 0;
			}
			for( l3 = 0; l3 < 3; l3++ )
			{
				sqr_flag = 0;
				sqr_row = l1*3 + l3;
				for( l4= 0; l4 < 3; l4++ )
				{
					sqr_column = l2*3 + l4;
					if( matrix[ sqr_row ][ sqr_column ] != 0 )
					{
						if( list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] == 0 )
						{
							list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] = 1;
						}
						else if( list_check[ matrix[ sqr_row ][ sqr_column ] - 1 ] == 1 )
						{
							printf("block%d #%d\n", l1*3 + l2 + 1, matrix[ sqr_row ][ sqr_column ] );
							change = 1;
							sqr_flag = 1;
							break;
						}
					}
				}
				if( sqr_flag == 1 )
				{
					break;
				}
			}
		}
	}
	if( change == 0 )
	{
		printf("true\n");
	}
	return 0;
}
