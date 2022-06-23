#include <stdio.h>
int main(void)
{
	int coins[4] = {500, 100, 50, 10};
	int change, i;
	int res[4];

	printf("Enter the amount of change: ");
	scanf("%d", &change);

	for( i = 0; i < 4; i++){
		res[i] = change / coins[i];
		change = change - ( res[i] * coins[i] );
	}

	printf("500 coin: %d\n100 coin: %d\n50 coin: %d\n10 coin:%d\n", res[0], res[1], res[2], res[3]);

	return 0;
}