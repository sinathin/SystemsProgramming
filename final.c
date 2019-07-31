#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
/*
Name: Sydney Anderson
Date: 2/19/2019
Descprition: C program to run bash

*/

int main(int argc, char **argv)
{
	pid_t childPid;
  	childPid = fork();
	if (childPid == 0){
	if (argc < 2)
   	{
       		fprintf(stderr, "INVALID\n");
       		// So 1 argument in command line means argc = 2.
       		return -1;
		exit(-1);
   	}
	//gets and stores the PID
	int PID = getpid();
	fprintf(stderr, "In child %i: ", PID);

	char str1[300] = "bash ";
	strcat(str1, argv[1]);
	strcat(str1, " ");

	//CREATE RANDOM NUM OF RADNOM NUMBERS
	srand(time(0));
	int NUM = rand()% (10 + 1 - 0) + 0;

	char buffer[50];
	for(int i=0; i<NUM; i++)
	{
		int tempNUM = rand()%11;
		sprintf(buffer, "%d", tempNUM);
		strcat(str1, buffer);
		strcat(str1, " ");
	}
	
	system(str1);
	exit(0);

	}

else{

	int returnStatus;
	waitpid(childPid, &returnStatus, 0);
	return 0;
}
}
