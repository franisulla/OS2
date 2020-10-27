#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fildes = open("ex1.txt", O_RDWR);
	char* str = "This is a nice day";	
	void* adr = mmap(NULL, strlen(str), PROT_WRITE, MAP_SHARED, fildes, 0);
	strncpy(adr, str, strlen(str));
	munmap(adr, strlen(str));
	ftruncate(fildes, strlen(str));
	close(fildes);
	return 0;
}
