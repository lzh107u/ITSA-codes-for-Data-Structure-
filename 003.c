#include<stdio.h>
#include<stdlib.h>
/*

	�D�غ��}�G https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1291
	
	�D�ءG ��J���ӼƦr��A��X�U�����ߤ��`�M 

	�L�{�G
		�ŧi array[ 6 ] �x�s��J��ơA�� for �j��N tmp �]����e����( array[ l1 ] )���T����
		�A�N tmp �[�� sum �A�̫�A��X sum  

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
