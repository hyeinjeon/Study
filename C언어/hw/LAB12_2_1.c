#include <stdio.h>
int main(void)
{
	int state;
	FILE * fp;
	char ch;

	fp = fopen("hello.txt", "at");
	if (fp == NULL) 
	{
		printf("file open error!\n");
		return 1;
	}

	fprintf(fp, "Hi\n");
	fprintf(fp, "Everybody\n");

	fclose(fp);
}