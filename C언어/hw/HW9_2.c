#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char myOwnNumber[15];
	char birthYear[5];
	int i;

	printf("주민등록번호 입력<'-'포함>: ");
	gets(myOwnNumber);
	strncpy(birthYear, myOwnNumber, 2);
	i = atoi(birthYear);

	printf("당신은 %d년도 생이군요.\n", 1900 + i);

	if(myOwnNumber[7] == '1'){
		printf("남자분이시군요.\n");
		printf("평균 수명 77를 더하면 %d까지 산다고 계산됩니다.\n", 1900 + i + 77);
	}
	else if(myOwnNumber[7] == '2'){
		printf("여자분이시군요.\n");
		printf("평균 수명 84를 더하면 %d까지 산다고 계산됩니다.\n", 1900 + i + 84);
	}

}