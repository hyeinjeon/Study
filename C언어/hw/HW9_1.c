#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50]; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50]; // ��ҹ��ڸ� �ٲ�
	char digitString[50];	
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�

	int i;
	int idx1 = 0, idx2 = 0, idx3 = 0, idx4 = 0;

	printf("���ڿ��� �Է��ϼ���:");
	scanf("%s", &string);

	for(i = 0; string[i] != '\0'; i++){
		if(isalpha(string[i]))
			alphaString1[idx1++] = string[i];
		else if (isdigit(string[i]))
			digitString[idx2++] = string[i];
	}

	alphaString1[idx1] = '\0';
	digitString[idx2] = '\0';

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);

	for(i = 0; alphaString1[i] != '\0'; i++)
		alphaString2[idx4++] = toupper(alphaString1[i]);

	alphaString2[idx4] = '\0';

	for(i = 0; alphaString1[i] != '\0'; i++)
		convertedString[idx3++] = alphaString1[i];
	for(i = 0; digitString[i] != '\0'; i++)
		convertedString[idx3++] = digitString[i];

	convertedString[idx3] = '\0';

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
} 