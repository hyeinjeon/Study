#define TRUE 1
#define FALSE 0
#include <stdio.h>

int is_arithmetic_sequence(int arr[], int size, int common)
{
	int i, res = 1;

	for(i = size; i > 1 ; i--){
		if(arr[i - 1] - common != arr[i - 2]){
			res = 0;
			break;
		}
	}
	
	if (res)
		return TRUE;
	else
		return FALSE;
}
int main(void)
{
	int a[10] = {1, 5, 9, 13, 17, 21, 25, 29, 33, 37};
	int x[10] = {1, 5, 9, 13, 17, 21, 25, 29, 33, 38};

	printf("%d ", is_arithmetic_sequence( a, 10, 4));
	printf("%d ", is_arithmetic_sequence( a, 10, 5));
	printf("%d\n", is_arithmetic_sequence( x, 10, 4));
}