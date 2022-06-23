#define SIZE 10
#include <stdio.h>

char askReservation();
void printSeats(int s[], int size);
void processReservation(int s[], int size, int seatNumber);

int main(void)
{
	int seatChoice;
	int seats[SIZE] = {0};

	printf("******�¼� ���� �ý���******\n");
	printf("---------------------\n1 2 3 4 5 6 7 8 9 10\n---------------------\n0 0 0 0 0 0 0 0 0 0 \n");

	while (askReservation() == 'y')
	{		
		printf("���° �¼�? ");
		scanf("%d", &seatChoice);

		processReservation(seats, SIZE, seatChoice);

		while (getchar() != '\n');
	}
}

char askReservation()
{
	char choice;
	printf("\n�¼��� �����Ͻðڽ��ϱ�?(y/n)");
	scanf("%c", &choice);
	return choice;
}

void processReservation(int s[], int size, int seatNumber)
{
	if (s[seatNumber - 1] == 0) {
			s[seatNumber - 1] = 1;
			printf("����Ǿ����ϴ�.\n");
			printSeats(s, SIZE);
		}
		else
			printf("�̹� ����� �ڸ��Դϴ�.\n");
}

void printSeats(int s[], int size)
{
    int i;
	printf("---------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");
	printf("----------------------\n");
	for(i = 0; i < size; i++)
		printf("%d ", s[i]);
	printf("\n");
}
