#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	FILE *fp1, *fp2;
	int num, i, total = 0;

	fp1 = fopen("random.txt", "wt");
	if(fp1 == NULL)
		printf("파일 오픈 에러\n");
		
	srand(time(NULL));
	for(i = 0; i < 10; i++) {
		num = rand() % 100;
		fprintf(fp1, "%d\n", num);
	}
	fclose(fp1);
	
	fp2 = fopen("output.txt", "wt");
	if(fp2 == NULL) 
		printf("파일 오픈 에러\n");
		
	fp1 = fopen("random.txt", "rt");
	if(fp1 == NULL)
		printf("파일 오픈 에러\n");

	fscanf(fp1, "%d", &num);
	while(!feof(fp1)) {
		fprintf(fp2, "%d\n", num);
		fprintf(stdout, "%3d", num);
		total += num;
		fscanf(fp1, "%d", &num);
	}

	fprintf(fp2,"\n합은 %d\n", total);
	fprintf(stdout, "\n합은 %d\n", total);
	fclose(fp1);
	fclose(fp2);
}