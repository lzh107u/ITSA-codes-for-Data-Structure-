#include<stdio.h>
#include<stdlib.h>
/*

	題目網址： https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1291
	
	題目： 輸入六個數字後，輸出各元素立方總和 

	過程：
		宣告 array[ 6 ] 儲存輸入資料，用 for 迴圈將 tmp 設為當前元素( array[ l1 ] )的三次方
		再將 tmp 加給 sum ，最後再輸出 sum  

*/
int main()
{
	int array[ 6 ];
	int l1;
	int sum = 0;
	int tmp;
	scanf("%d %d %d %d %d %d", &array[ 0 ], &array[ 1 ], &array[ 2 ], &array[ 3 ], &array[ 4 ], &array[ 5 ] );
	
	for( l1 = 0; l1 < 6; l1++ )
	{
		tmp = array[ l1 ] * array[ l1 ] * array[ l1 ];
		sum = sum + tmp;
	}
	printf("%d\n", sum );
	return 0;
}
