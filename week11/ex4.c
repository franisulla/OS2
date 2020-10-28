#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fildes1 = open("ex1.txt", O_RDONLY);
	int fildes2 = open("ex1.memcpy.txt", O_CREAT | O_RDWR, 0600);
	
	struct stat statbuf;
	fstat (fildes1, &statbuf);
	size_t n = statbuf.st_size;
	
	ftruncate(fildes2, n);

	char* adr1 = mmap(NULL, n, PROT_READ, MAP_SHARED, fildes1, 0);
	char* adr2 = mmap(NULL, n, PROT_WRITE, MAP_SHARED, fildes2, 0);

	memcpy(adr2, adr1, n);

	munmap(adr1, n);
	munmap(adr2, n);

	close(fildes1);
	close(fildes2);
	return 0;
}
