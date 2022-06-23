#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int data[100];
	int num, i;
	int count[100] = {0};

	srand(time(NULL));

	printf("Enter the number of random numbers:<<=100>:");
	scanf("%d", &num);

	for(i = 0; i < num; i++)
		data[i] = rand()%10;

	for(i = 0; i < num; i++){
		if(data[i] == 0)
			count[0]++;
		else if(data[i] == 1)
			count[1]++;
		else if(data[i] == 2)
			count[2]++;
		else if(data[i] == 3)
			count[3]++;
		else if(data[i] == 4)
			count[4]++;
		else if(data[i] == 5)
			count[5]++;
		else if(data[i] == 6)
			count[6]++;
		else if(data[i] == 7)
			count[7]++;
		else if(data[i] == 8)
			count[8]++;
		else if(data[i] == 9)
			count[9]++;
	}

	for(i = 0; i < 10; i++)
		printf("%d의 개수는 %d\n", i, count[i]);

	printf("-------------------------------------------\n");
	printf("발생된 난수는\n");

	for(i = 0; i < num; i++){
		if(i%5 == 0)
			printf("\n");
		printf("%5d", data[i]);
	}

	printf("\n");

	return 0;
}