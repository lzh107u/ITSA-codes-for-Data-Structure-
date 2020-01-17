#include<stdio.h>
#include<stdlib.h>
/*

	題目： 輸入六位數字後，印出反轉結果。 

	過程：
		首先宣告 array[ 6 ] 來儲存讀入的六個數字，再用 for 迴圈倒反印出來 
		在迴圈中有分兩種 case :
			若不是最後一項 ( array[ 0 ] )，則數字後面印空白	-	( 1 )
			若是最後一項 ( array[ 0 ] ) ，則數字後面印換行 	-	( 2 )
			
*/
int main()
{
	int array[ 6 ];
	
	int l1;
	
	scanf("%d %d %d %d %d %d", &array[ 0 ], &array[ 1 ], &array[ 2 ], &array[ 3 ], &array[ 4 ], &array[ 5 ] );
	for( l1 = 5; l1 >= 0; l1-- )
	{
		if( l1 != 0 )			//	( 1 )
		{
			printf("%d ", array[ l1 ] );	
		}
		else if( l1 == 0)		//	( 2 )
		{
			printf("%d\n", array[ l1 ] );
		}
	}
	return 0;
}
