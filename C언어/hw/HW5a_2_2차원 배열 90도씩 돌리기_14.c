#include	<stdio.h>
void printData(int arr[][4]);
void rotateData(int arr[][4]);
int main(void) {
	int data[4][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	int i;

	printData(data);

	for(i = 0;i < 4;i++) {
		rotateData(data);
	}
}
void printData(int arr[][4]) {
	int i, j;

	for(i = 0;i < 4;i++) {
		for(j = 0;j < 4;j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void rotateData(int arr[][4]) {
	int i, j;
	int temp[4][4];
	
	for(i = 0;i < 4;i++) {	
		for(j = 0;j < 4;j++) {
			temp[j][3-i] = arr[i][j];	
		}
	}

	for(i = 0;i < 4;i++) {
		for(j = 0;j < 4;j++) {
			arr[i][j] = temp[i][j];
		}
	}
	
	printData(arr);
}
