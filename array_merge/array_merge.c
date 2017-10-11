#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "array_merge.h"


int* two_array_merge1(int size1, int* array1, int size2, int* array2){
	int* jj;
	int* fin;
	int i,j,k;

	jj =(int*) calloc(size1+size2,sizeof(int));
	for (i = 0; i < size1; i++){
		jj[i] = array1[i];
	}
	for (j = 0; j < size2; j++){
		jj[size1+j] = array2[j];
	}
	fin =(int*) calloc(size1+size2+1,sizeof(int));
	fin[0] = size1+size2;
	for (k = 0; k < size1+size2; k++){
		fin[k+1] = jj[k];
	}
	free(jj);
	return fin;
}

int* two_array_merge2(int* array1, int size2, int* array2){
	int* jj;
	int* final;
	int i,j,k;
	int size1;

	size1 = array1[0];	
	jj =(int*)  calloc(size1+size2, sizeof(int));
	for (i = 1; i < size1+1 ; i++){
		jj[i-1] = array1[i];
	}
	for (j = 0; j < size2; j++){
		jj[size1+j] = array2[j];
	}
	final =(int*)  calloc(size1+size2+1,sizeof(int));
	final[0]=size1+size2;
	for (k = 0; k < size1+size2; k++){
		final[k+1] = jj[k];
	}
	free(jj);
	return final;
}

int* check_dupl1(int* array){
	int i,j,k;
	int* jj;
	int* ff;
	int repeatTimes;
	int pointer=0;
	int size;
	size = array[0];
	jj=(int*) calloc(size+1,sizeof(int));
	for (i = 1; i < size+1; i++){
		repeatTimes = 0;
		for (j = i+1; j < size+1; j++){
			if (array[i] == array[j]){
				repeatTimes++;
			}
		}
		if (repeatTimes == 0){
			jj[pointer] =  array[i];
			pointer++;
		}
	}
	ff=(int*) calloc(pointer,sizeof(int));
	ff[0]=pointer;
	for (k = 0; k < pointer; k++){
		ff[k+1] = jj[k];
	}
	free(jj);
	return ff;
}

int* check_dupl2(int size,int* array){
	int i,j,k;
	int* jj;
	int* ff;
	int repeatTimes;
	int pointer=0;
	jj=(int*) calloc(size+1,sizeof(int));
	for (i = 0; i < size; i++){
		repeatTimes = 0;
		for (j = i+1; j < size; j++){
			if (array[i] == array[j]){
				repeatTimes++;
			}
		}
		if (repeatTimes == 0){
			jj[pointer] =  array[i];
			pointer++;
		}
	}
	ff=(int*) calloc(pointer,sizeof(int));
	ff[0]=pointer;
	for (k = 0; k < pointer; k++){
		ff[k+1] = jj[k];
	}

	free(jj);
	return ff;
}

int* get_part_of_array(int* array){
	int size;
	int* fin;
	int i;
	size = array[0];
	fin = (int*) calloc(size,sizeof(int));
	for (i = 0; i < size; i++){
		fin[i] = array[i+1];
	}
	return fin;
}

int* put_back_to_array(int size, int* array){
        int i;
        int* fin;
        fin = (int*) calloc(size+1,sizeof(int));
        fin[0]=size;
        for (i = 1; i<size+1; i++){
                fin[i]= array[i-1];
        }
        return fin;
}
	


void mergesort(int size, int* array);

int* array_merge(int num_arrays, int* sizes, int** values){
	int i;
	int* test;
	int* result;
	int* array0;
	int* array1;
	int size;
	if (num_arrays == 0){
		result =(int*) calloc(1,sizeof(int));
		result[0]=0;
		return result;
	} else if (num_arrays == 1){
		array0 = check_dupl2(sizes[0],values[0]);
		size = array0[0];
		array1 = get_part_of_array(array0);
		mergesort(size,array1);
		result = put_back_to_array(size,array1);
		free(array0);
		free(array1);
		return result;
	} else {
		test = (int*) two_array_merge1(sizes[0],values[0],sizes[1],values[1]);
		for (i = 2; i < num_arrays; i++){
			test = (int*) two_array_merge2(test,sizes[i],values[i]);
		}
		array0 = check_dupl1(test);
		size = array0[0];
		array1 = get_part_of_array(array0);
		mergesort(size,array1);
		result = put_back_to_array(size,array1);
		free(test);
		free(array0);
		free(array1);
		return result;
	}
}

