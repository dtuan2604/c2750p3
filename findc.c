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
	int targetChar = 99;
	int inputChar;
	int numChar = 0;
	int checkFlag = 0;
	int option;
	while( (option = getopt(argc, argv, "hf:c:")) != -1){
		switch(option){
			case 'h':
				help();
				return 1;
			case 'f':
				inputFile = optarg;
				checkFlag = 1;
				break;
			case 'c':
				targetChar = atoi(optarg);
				printf("Test %c\n",targetChar);
				break;		
			case '?':
				if (optopt == 'c' || optopt == 'f'){
					fprintf (stderr, "Option -%c requires an argument.\n",optopt);
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
	if(checkFlag == 1){
		printf("Input File: %s.\n", inputFile);
	        printf("Target Character: %c.\n", targetChar);
		FILE * inputPointer = fopen(inputFile, "r");
		if (inputPointer == NULL){
			printf("Couldn't read the file!\n The file doesn't exist or isn't readable");
			return EXIT_FAILURE;
		}
			
		do{
			inputChar = fgetc(inputPointer);
			if(inputChar == EOF)
				break;
			if (inputChar == targetChar)
				numChar++;
			
		}while (inputChar != EOF);
		fclose(inputPointer);	
	}
	else{
	 	inputChar = getchar();
		printf("Input: ");
		while(inputChar != EOF){
                	putchar(inputChar);
			if(inputChar == targetChar)
                        	numChar++;
                	inputChar = getchar();
       		}

	}
	
	printf("Number of '%c' found: %d.", targetChar, numChar);  
	return EXIT_SUCCESS;
}
