#include <stdio.h>
int printArray();
int main(void)
{
	int i;
	int list[10] = {1, 3, 4, 5, 7, 8, 9, 10, 11, 12};
	int evenList[10];
	int k = 0;

	for(i = 0; i  < 10; i++){
		if( list[i]%2 == 0 ){
			evenList[k] = list[i];
			k++;
		}
	}
	
	printArray(evenList, k);
}
int printArray(int a[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d  ", a[i]);
	printf("\n");
}