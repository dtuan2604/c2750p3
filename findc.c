#include <stdio.h>
#include <stdlib.h>

void help(){
	printf("The options for this program are: \n");
	printf("-f: input filename (required)\n");
	printf("-c: specifies a different character to look for in the target file. By default, this is character c\n"); 
}




int main(int argc, char** argv){
	char* inputFile = NULL;
	char targetChar = 'c';
	int option;
	while( (option = getopt(argc, argv, "hf:c:")) != -1){
		switch(option){
			case 'h':
				help();
				break;
			case 'f':
				inputFile = optarg;
				break;
			case 'c':
				targetChar = optarg;
				break;		
			case '?': 
		}

	}

}
