#include <stdio.h>
#include <unistd.h>


int main(){
	setvbuf(stdout, NULL, _IOLBF, 0);
	char* word = "Hello";
	for (int i=0; i<5; i++){
		printf("%c", *(word + i));
		sleep(1);
	}
	printf("\n");
	return 0;
}
