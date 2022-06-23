#include <stdio.h>
int get_cycle_number(int n, int length)
{
	length++;
	if(n % 2 == 0){
		n = n/2;
		printf("%d ", n);
		return get_cycle_number(n, length);
	}
	else if(n == 1){
		printf("\n±æÀÌ´Â %d\n", length);
		return 1;
	}
		
	else{
		n = n * 3 + 1;
		printf("%d ", n);
		return get_cycle_number(n, length);
	}
}
int main(void)
{
	int length = 0, num;

	printf("Enter the number: ");
	scanf("%d", &num);

	get_cycle_number(num, length);
}