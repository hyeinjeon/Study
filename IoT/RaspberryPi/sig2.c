#include <stdio.h>
#include <signal.h>

void main()
{	void  (*oldHandler)();			
	printf("I can be Control-C’ed \n");
	sleep(3);

	oldHandler = signal(SIGINT, SIG_IGN); 	
	printf("I’m protected from Control-C now \n");
	sleep(3);

	signal(SIGINT, oldHandler);		
	printf("I can be Control-C’ed again \n");
	sleep(3);
	printf("Bye! \n");
}

