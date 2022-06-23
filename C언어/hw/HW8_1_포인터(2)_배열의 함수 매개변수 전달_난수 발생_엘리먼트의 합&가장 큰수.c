#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumUpData(int *, int);
void printData(int *, int);
int maxData(int *, int);

void main()
{
	int k;
	int *p;
	int sum;

	int data[10];

	p = data;
	srand(time(NULL));

	for(k = 0; k < 10; k++)
		*p++ = rand() % 100;

	sum = sumUpData(data, 10);
	printf("엘리먼트의 합은 %d\n", sum);

	printf("엘리먼트들은 ");
	printData(data, 10);
	
	printf("\n엘리먼트들 중 가장 큰 수는 %d\n", maxData(data, 10));
}
int sumUpData (int *p1, int size)
{
	int i, total = 0;
	for(i = 0; i < size; i++)
		total += *(p1 + i);
	return total;
}
void printData (int *p2, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", *(p2 + i));
}
int maxData(int *p3, int size)
{
	int i, max = *p3;
	for(i = 1; i < size; i++)
		if(max < *(p3 + i))
			max = *(p3 + i);
	return max;
}