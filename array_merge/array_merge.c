#include <stdlib.h>
#include <string.h>

#include "array_merge.h"

/*int* array_merge(int num_arrays, int* sizes, int** values){
	return [0];	
}*/

int* two_array_merge(int size1, int* array1, int size2, int* array2){
	int* jj;
	int* fin;
	int i,j;
	int pointer;
	int repeatTimes = 0;


	jj =(int*)  calloc(size1+size2+1, sizeof(int));
	for (i = 0; i < size1; i++){
		jj[i] = array1[i];
	}
	pointer = size1;
	for (j = 0; j < size2; j++){
		for (i = 0; i < size1; i++){
			if (array2[j] == array1[i]){
				repeatTimes++;
			}
		}
		if (repeatTimes == 0){
			jj[pointer] =  array2[j];
			pointer++;
		}
	}
	fin =(int*)  calloc(pointer,sizeof(int));
	for (i = 0; i < pointer; i++){
		fin[i] = jj[i];
	}
	free(jj);
	return fin;
}

int main(int argc, char* argv[]) {
	int array1[] = {3,2,0,5};
	int array2[] = {8,9};

	printf("%s\n", two_array_merge(4,array1,2,array2));
}
