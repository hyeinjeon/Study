#include <stdio.h>

struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};

int main(void)
{
	struct student s[3];
	struct student *sp = s;
	int i;
	int midAverage = 0;
	int finAverage = 0;

	for(i = 0; i < 3; i++){
		printf("Enter student name:");
		scanf("%s", &sp -> name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp -> midterm, &sp -> final);
		sp -> average = (sp -> midterm + sp -> final) / 2;
		sp++;
	}

	sp = s;

	printf("�̸� \t �߰� \t �б⸻ \t ��� \n");
	for(i = 0; i < 3; i++){
		printf("%s \t %d \t %d \t %d \n", sp -> name, sp -> midterm, sp -> final, sp -> average);
		sp++;
	}

	printf("\n");

	sp = s;

	printf("�̸� \t ���� \n");
	for(i = 0; i < 3; i++){
		if(sp -> average >= 80)
			printf("%s \t A \n", sp -> name);
		else if (sp -> average >= 50)
			printf("%s \t B \n", sp -> name);
		else if (sp -> average <= 50)
			printf("%s \t F \n", sp -> name);
		sp++;
	}

	sp = s;

	printf("\n");

	printf("�߰������ ��� = ");
	for(i = 0; i < 3; i++){
		midAverage += sp -> midterm;
		sp++;
	}
	printf("%d\n", midAverage / 3);
	
	sp = s;

	printf("�б⸻����� ��� = ");
	for(i = 0; i < 3; i++){
		finAverage += sp -> final;
		sp++;
	}
	printf("%d\n", finAverage / 3);

}