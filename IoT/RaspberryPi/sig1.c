#include <stdio.h>
#include <signal.h>

int alarmFlag = 1;

void alarmHandler()
{
	printf("An alarm clock signal was received \n");
	alarmFlag = 0;
}

void main()
{
	signal(SIGALRM, alarmHandler);
	alarm(3);
	printf("Looping...\n");
	while(alarmFlag)
		pause();
	printf("Looping ends due to alarm signal \n");
}
