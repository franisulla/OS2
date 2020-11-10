#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc < 2){
		printf("Please specify name of file(input_ok.txt or input_dl.txt) as command line parameter\n");
		return 0;
	}
	FILE* pf = fopen(argv[1], "r");

	int p, r;
	fscanf(pf, "%d %d", &r, &p);
	
	int* E = (int*) malloc(sizeof(int)*r);
	int* A = (int*) malloc(sizeof(int)*r);

	for (int i=0; i<r; i++){
		fscanf(pf, "%d", E+i);	
	}
	for (int i=0; i<r; i++){
		fscanf(pf, "%d", A+i);	
	}

	int** C = (int**)malloc(p*sizeof(int*));
	for (int i=0; i<p; i++){
		C[i] = (int*) malloc(r*sizeof(int));
		for (int j=0; j<r; j++){
			fscanf(pf, "%d", C[i]+j);
		}
	}

	
	int** R = (int**)malloc(p*sizeof(int*));
	for (int i=0; i<p; i++){
		R[i] = (int*) malloc(r*sizeof(int));
		for (int j=0; j<r; j++){
			fscanf(pf, "%d", R[i]+j);
		}
	}

	int i=0, iterations=p*p;
	while (iterations--){
		int eliminable=1;
		for (int j=0; j<r; j++){
			if (A[j] < R[i][j]){
				eliminable=0;
				break;
			}
		}
		if (eliminable){
			for (int j=0; j<r; j++){
				A[j] += C[i][j];
				C[i][j] = 0;
			}
		}
		i++;
		if (i==p) i=0;
	}

	int deadlock_count=0;
	for (int i=0; i<p; i++){
		for (int j=0; j<r; j++){
			if (C[i][j]){
				deadlock_count++;
				R[i][0] = -1;
				break;
			}
		}
	}

	if (!deadlock_count){
		printf("No deadlocks detected\n");
	}
	else{
		printf("%d processes in a deadlock: ", deadlock_count);
		for (int i=0; i<p; i++){
			if (R[i][0] == -1)
				printf("%d ", i);
		}
	}
}
