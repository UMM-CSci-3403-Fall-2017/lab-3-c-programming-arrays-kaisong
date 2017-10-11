#include <stdlib.h>
#include <stdio.h>

#include "mergesort.h"

void merge(int* p, int low, int mid, int high){
	int i,k;
	int* temp;//merge to arrays together
	int start1 = low;
	int end1 = mid;
	int start2 = mid+1;
	int end2 = high;
	temp = (int*) calloc(high-low+1,sizeof(int));
	//compare the two elements that in the two different temp arrays, and find the smaller one put that to the merge space and move our pointer to the next element
	for (k = 0; start1 <= end1 && start2 <= end2; k++){
		if(p[start1] < p[start2]){
			temp[k] = p[start1];
			start1++;
		}else{
			temp[k] = p[start2];
			start2++;
		}
	}
	// if we have element(s) left, we will copy the left elements directly to the merge space
	while(start1 <= end1){
		temp[k] = p[start1];
		k++;
		start1++;
	}
	while(start2 <= end2){
		temp[k] = p[start2];
		k++;
		start2++;
	}

	//copy the sorted array to original one
	for (i = 0; i < high-low+1; i++){
		p[low+i] = temp[i];
	}

	//merge the process
	free(temp);
}

void mergesort1(int* p, int low, int high){
	int mid = (low +high)/2;
	if (low < high){
		mergesort1(p,low,mid); //merge sort left side 
		mergesort1(p,mid+1,high);  //merge sort right side
		merge(p,low,mid,high); //merge them together
	}
}

void mergesort(int size, int* p){
        mergesort1(p,0,size-1); //translate the form of mergesort into mergesort(int*, int, int)
}

