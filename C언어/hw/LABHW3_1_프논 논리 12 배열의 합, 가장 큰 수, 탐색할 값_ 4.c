#include <stdio.h>
int sumList(int arr[], int size);
int maxList(int arr[], int size);
int indexSearch(int arr[], int size, int key);
int main(void)
{
	int list[10] = {10, 20, 30, 40, 50, 40, 30, 20, 10, 0};
	int value;
	int keyIndex;
	int i;

	printf("���� %d\n", sumList(list, 10));
	printf("���� ū ���� %d\n", maxList(list, 10));
	printf("Ž���� ����? ");
	scanf("%d", &value);

	if(indexSearch(list, 10, value) == 0)
		printf("����\n");
	else
		printf("%d��°�� �ִ�\n", indexSearch(list, 10, value));

	return 0;
}
int sumList(int arr[], int size)
{
	int i, total = 0;
	for (i = 0; i < size; i++)
		total += arr[i];
	return total;
}
int maxList(int arr[], int size)
{
	int i, max = -1;
	for(i = 0; i < size; i++)
		if(max < arr[i])
			max = arr[i];
	return max;
}
int indexSearch(int arr[], int size, int key) 
{
	int i;
	for(i = 0; i < 10; i++)
		if(key == arr[i])
			return i+1;
	return 0;
}