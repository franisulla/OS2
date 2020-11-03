#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

int main (int argc, char** argv){
	char* input = (char*) calloc(MAX_SIZE, sizeof(char));
	
	ssize_t nread = read (0, input, MAX_SIZE);
	
	char* aflag = "-a";
	int i=1; //counter of files in argv
	bool append = argc > 1 && strcmp(argv[1], aflag) == 0;
	if (append) i++;
	
	for (; i<argc; i++){
		int fd;
		if (append) fd = open(argv[i], O_RDWR | O_CREAT | O_APPEND, 0660);
		else fd = open(argv[i], O_RDWR | O_CREAT, 0666);
		
		ssize_t nwrite = write (fd, input, strlen(input));
		if (!append) ftruncate (fd, nwrite);
		close (fd);	
	}

	ssize_t nwrite = write (1, input, strlen(input));
	  
	return 0;
	

}

