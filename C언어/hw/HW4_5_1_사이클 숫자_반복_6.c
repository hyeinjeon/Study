#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
	int num;

	printf("Enter a number:");
	scanf("%d", &num);
	get_cycle_number(num);
}
int get_cycle_number(int n)
{
	int plus = 1;
	printf("%d ", n);
	while(1){
		if(n % 2 == 0){
			n = n/2;
			plus++;
			printf("%d ", n);
		}
		else if( n == 1)
			break;
		else {
			n = n*3 + 1;
			plus++;
			printf("%d ", n);
		}
	}
	printf("\n");
	printf("사이클 길이는 %d\n", plus);
}