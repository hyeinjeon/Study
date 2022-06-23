#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	alarmFlag = 1;

void myFunc()
{
	signal(SIGINT,SIG_IGN);
	printf("signal ignore\n");
	exit(1);
}

void   alarmHandler()
{	printf("알람 울리기\n");
	signal(SIGINT, myFunc);
}

void   main()
{
	signal(SIGALRM, alarmHandler);
	alarm(3);

	printf("알람 기다리기 Control C 작동\n");
	while(alarmFlag)	
		pause();

	printf("알람 종료\n");
}
