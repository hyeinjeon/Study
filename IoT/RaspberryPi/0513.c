#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include <errno.h>

int	alarmFlag = 1;

#define NEAR_OUT 3 // J14
#define FAN	22 //J29

void   alarmHandler()
{	
	//팬 동작 정지
	digitalWrite (FAN, 0) ;
	signal(SIGINT,SIG_DFL); //   컨트롤씨정상작동하게 바꿈
}

void myInterrupt(void)
{
	printf("near\n");
	// 팬 작동
	digitalWrite (FAN, 1) ;
	signal(SIGINT,SIG_IGN); //컨트롤 씨 무시하도록

	signal(SIGALRM, alarmHandler);
	alarm(6);

	while(alarmFlag)	
		pause();

}

void main()
{
	if(wiringPiSetup() < 0) 
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
		return 1;
	}

	pinMode(NEAR_OUT, INPUT);
	pinMode(FAN, OUTPUT) ;

	if(wiringPiISR (NEAR_OUT, INT_EDGE_RISING, &myInterrupt) <0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));	
		return 1;		
	}	

	while(1) {
		printf("monitoring..\n");
		delay(1000);

		if(wiringPiSetup() < 0) 
		{
			fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
			return 1;
		}

		pinMode(NEAR_OUT, INPUT);
		pinMode (FAN, OUTPUT) ;

		if(wiringPiISR (NEAR_OUT, INT_EDGE_RISING, &myInterrupt) <0)
		{
			fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));	
			return 1;		
		}
		
	}

	return 0;
}
