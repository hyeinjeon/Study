#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LIGHTSEN_OUT 0  //  J12 connect
#define NEAR_OUT 3 // J14
void myInterrupt(void)
{
	printf("light\n");
	delay(500);
}

void myInterrupt2(void)
{
	printf("near\n");
	delay(500);
}

int main(void) 
{
	
	if(wiringPiSetup() < 0) 
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
		return 1;
	}

	pinMode(LIGHTSEN_OUT, INPUT);
	
	if(wiringPiISR (LIGHTSEN_OUT, INT_EDGE_RISING, &myInterrupt) <0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));	
		return 1;		
	}	

	if(wiringPiISR (NEAR_OUT, INT_EDGE_RISING, &myInterrupt2) <0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));	
		return 1;		
	}	



	while ( 1 ) 
	{	
		delay( 4000 ); // wait 1 second
	}

	return 0;
}
