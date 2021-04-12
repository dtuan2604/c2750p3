#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void help(){
	printf("The options for this program are: \n");
	printf("-f: input filename (required)\n");
	printf("-c: specifies a different character to look for in the target file. By default, this is character c\n"); 
}

int countfromStdin(char targetChar){
	char inputChar = getchar();
	int count = 0;
	while(inputChar != EOF){
		if (inputChar == targetChar)
			count++;
		inputChar = getchar();
	}
	return count;

}


int main(int argc, char** argv){
	char * inputFile = NULL;
	char targetChar = 'c';
	char inputChar;
	int numChar = 0;
	int checkFlag = 0;
	int option;
	while( (option = getopt(argc, argv, "hf:c:")) != -1){
		switch(option){
			case 'h':
				help();
				break;
			case 'f':
				inputFile = optarg;
				checkFlag = 1;
				break;
			case 'c':
				targetChar = atoi(optarg);
				break;		
			case '?':
				if (optopt == 'c' || optopt == 'f'){
					fprintf (stderr, "Option -%c requires an argument.\n",optopt);
					break;
				}
				else if ( isprint(optopt))
					fprintf (stderr, "Unknown option `-%c`.\n", optopt);
				else
					fprintf(stderr, "Unknow option character `\\x%x`. \n", optopt);
				return EXIT_FAILURE;
			default:
				help();
				break; 
		}

	}

	printf("Input File: %s.\n", inputFile);
	printf("Target Character: %c.\n", targetChar);
	if(checkFlag == 1){
		FILE * inputPointer = fopen(inputFile, "r");
		if (inputPointer == NULL){
			printf("Null File Pointers!\n");
			return EXIT_FAILURE;
		}
			
		do{
			inputChar = fgetc(inputPointer);
			if(inputChar == EOF)
				break;
			if (inputChar == targetChar)
				numChar++;
			
		}while (inputChar != EOF);	
	}
	else
		numChar = countfromStdin(targetChar);
	
	printf("Number of '%c' found: %d.", targetChar, numChar);  

	return EXIT_SUCCESS;
}
