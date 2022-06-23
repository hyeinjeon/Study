#include <stdio.h>
#include <ctype.h>
int main(void)
{
	FILE *fp1, *fp2;
	char introduce[200] = "Near far\nwherever you are\nI believe that the heart does go on\nOnce more, you open the door\nAnd you're here in my heart\nAnd my heart will go on and on";
	char ch;

	fp1 = fopen("input.txt", "wt");
	if(fp1 == NULL) {
		printf("파일 오픈 에러\n");
		return 1;
	}

	fprintf(fp1, "%s", introduce);
	fclose(fp1);

	fp1 = fopen("input.txt", "rt");
	if(fp1 == NULL) {
		printf("파일 오픈 에러\n");
		return 1;
	}
	fp2 = fopen("output.txt", "wt");
	if(fp2 == NULL) {
		printf("파일 오픈 에러\n");
		return 1;
	}

	ch = getc(fp1);
	while(!feof(fp1)) {
		if(islower(ch))
			putc(toupper(ch), fp2);
		else
			putc(ch, fp2);
		ch = getc(fp1);
	}

	fprintf(fp2, "\n\n\n");
	fseek(fp1, 0, SEEK_SET);

	ch = getc(fp1);
	while(!feof(fp1)) {
		if(isupper(ch))
			putc(tolower(ch), fp2);
		else
			putc(ch, fp2);
		ch = getc(fp1);
	}
}