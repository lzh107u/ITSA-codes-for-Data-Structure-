#include<stdio.h>
#include<stdlib.h>
/*

	�D�ءG ��J����Ʀr��A�L�X���൲�G�C 

	�L�{�G
		�����ŧi array[ 6 ] ���x�sŪ�J�����ӼƦr�A�A�� for �j��ˤϦL�X�� 
		�b�j�餤������� case :
			�Y���O�̫�@�� ( array[ 0 ] )�A�h�Ʀr�᭱�L�ť�	-	( 1 )
			�Y�O�̫�@�� ( array[ 0 ] ) �A�h�Ʀr�᭱�L���� 	-	( 2 )
			
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
