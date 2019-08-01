#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
/*
Name: Sydney Anderson
Date: 2/21/19

 	IMPORTANT NOTE: To use cd properly you have to have an space aftter the location you want to go to
		ex. NOT -> cd[space]..	
		ex. DO THIS -> cd[space]..[space]
*/

int main(int argc, const char **argv) {

	char direct[200];
	fprintf(stderr, "%s$ ", getcwd(direct,200));
	char exits[] = "exit";
	char cd[] = "cd";
	char pwd[] = "pwd";

	char userIn[100];
	//fgets(userIn,100, stdin);
	fflush(stdout);
	scanf("%[^\n]%*c", userIn);
	
	if(strcmp(exits, userIn) == 0){
		return 0;
	}
	else{
		while(strcmp(exits, userIn) != 0){
			//iterate throuhe the string till reach space
			//store that and if that is cd, pwd, or exit
			char command[100];
			memset(&(command[0]), 0, 100);
			int i = 0;
			while(userIn[i] != ' ' && userIn[i] != '\0'){
				command[i] = userIn[i];
	 			i = i + 1;
			}
			if(strcmp(cd, command) == 0|| strcmp(pwd, command) == 0 || strcmp(exits, command) == 0){
				//call strtok
				char *token = strtok(userIn, " ");
				char *temp = strtok(NULL, " "); 
				if(strcmp(cd, token) != 0){ //if its exit or pwd
					system(userIn);
				}
				else{
					chdir(temp);
					//fprintf(stderr, "%s$ \n", getcwd(direct,200));
				}
			}

		/////////FORK A CHILD////////
			else{
				pid_t childPid;
   				childPid = fork();
				if (childPid == 0){
					system(userIn);
					exit(0);
					
				}
				else{

				int returnStatus;
				waitpid(childPid, &returnStatus, 0);
				//return 0;
				}
			}
			memset(&(command[0]), 0, 100);
			fprintf(stderr, "%s$ ", getcwd(direct,200));
			scanf("%[^\n]%*c", userIn);

		}


	}

	return 0;
}

