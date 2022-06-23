#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50]; // 입력되는 문자열을 저장
	char alphaString1[50]; // 입력문자열에서 알파벳만 저장
	char alphaString2[50]; // 대소문자를 바꿈
	char digitString[50];	
	char convertedString[50]; // 문자들과 숫자들로 재배열한 문자열

	int i;
	int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;

	printf("문자열을 입력하세요:");
	scanf("%s", &string);

	for(i = 0; string[i] != '\0'; i++){
		if(isalpha(string[i]))
			alphaString1[idx1++] = string[i];
		else if (isdigit(string[i]))
			digitString[idx2++] = string[i];
	}

	alphaString1[idx1] = '\0';
	digitString[idx2] = '\0';

	printf("문자들은 %s\n", alphaString1);
	printf("숫자들은 %s\n", digitString);

	for(i = 0; alphaString1[i] != '\0'; i++)
		alphaString2[idx4++] = toupper(alphaString1[i]);

	alphaString2[idx4] = '\0';

	for(i = 0; alphaString1[i] != '\0'; i++)
		convertedString[idx3++] = alphaString1[i];
	for(i = 0; digitString[i] != '\0'; i++)
		convertedString[idx3++] = digitString[i];

	convertedString[idx3] = '\0';

	printf("대소문자를 바꾼 문자들은 %s\n", alphaString2);
	printf("문자들과 숫자들로 재배열한 문자열은 %s\n", convertedString);
} 