#include <signal.h> //Signal 사용 헤더파일
#include <unistd.h>
#include <stdio.h> 
#include <string.h> 
#include <errno.h>
#include <stdlib.h> //exit() 사용 헤더파일

#include <wiringPi.h>

#define PUMP	21 // BCM_GPIO 5

int main (void)
{
	if (wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return 1 ;
	}

	pinMode (PUMP, OUTPUT) ;

	for (;;)
	{
		printf("here - pump on\n");
		digitalWrite (PUMP, 1) ; // On
		
		delay (2000) ; // ms
		
		digitalWrite (PUMP, 0) ; // Off
		
		delay (2000) ;
	}
	return 0 ;
}
