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
	int i;
	int midAverage = 0;
	int finAverage = 0;

	for(i = 0; i < 3; i++){
		printf("Enter student name:");
		scanf("%s", s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);
		s[i].average = (s[i].midterm + s[i].final) / 2;
	}

	printf("이름 \t 중간 \t 학기말 \t 평균 \n");
	for(i = 0; i < 3; i++)
		printf("%s \t %d \t %d \t %d \n", s[i].name, s[i].midterm, s[i].final, s[i].average);

	printf("\n");

	printf("이름 \t 학점 \n");
	for(i = 0; i < 3; i++)
		if(s[i].average >= 80)
			printf("%s \t A \n", s[i].name);
		else if (s[i].average >= 50)
			printf("%s \t B \n", s[i].name);
		else if (s[i].average <= 50)
			printf("%s \t F \n", s[i].name);

	printf("\n");

	printf("중간고사의 평균 = ");
	for(i = 0; i < 3; i++)
		midAverage += s[i].midterm;
	printf("%d\n", midAverage / 3);
	
	printf("학기말고사의 평균 = ");
	for(i = 0; i < 3; i++)
		finAverage += s[i].final;
	printf("%d\n", finAverage / 3);

}