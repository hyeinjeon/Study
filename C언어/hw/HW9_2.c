#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char myOwnNumber[15];
	char birthYear[5];
	int i;

	printf("�ֹε�Ϲ�ȣ �Է�<'-'����>: ");
	gets(myOwnNumber);
	strncpy(birthYear, myOwnNumber, 2);
	i = atoi(birthYear);

	printf("����� %d�⵵ ���̱���.\n", 1900 + i);

	if(myOwnNumber[7] == '1'){
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", 1900 + i + 77);
	}
	else if(myOwnNumber[7] == '2'){
		printf("���ں��̽ñ���.\n");
		printf("��� ���� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.\n", 1900 + i + 84);
	}

}