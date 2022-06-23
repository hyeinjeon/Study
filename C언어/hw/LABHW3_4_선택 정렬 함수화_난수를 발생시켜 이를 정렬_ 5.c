#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort();
int main(void)
{
	int data[10];
	int i;

	srand(time(NULL));

	printf("발생된 난수:\t");
	for(i = 0; i < 10; i++)
		data[i] = rand()%100;
	for(i = 0; i < 10; i++)
		printf("%d ",data[i]);
	printf("\n");

	printf("정렬후: \t");
	selectionSort(data,10);

	return 0;
}
void selectionSort(int list[], int size)
{
	int i, least, j, temp = 0;

	for(i = 0; i < size - 1; i++)
	{
		least = i;
		for(j = i + 1; j < size; j++)
			if(list[j] < list[least])
				least = j;

		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	for(i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}