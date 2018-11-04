/*
 * MergeSort.cpp
 *
 *  Created on: Nov 3, 2018
 *      Author: samarth
 */
#include<iostream>
using namespace std;

class MergeSorter{

public:
	void mergeArrays(int arr[],int leftStart,int middleIndex, int rightEnd){

		int i;
		int j;
		int k;
		int n1=middleIndex-leftStart+1;
		int n2=rightEnd-middleIndex;
		int l[n1];
		int r[n2];
		for(i=0;i<n1;i++){
			l[i]=arr[i+leftStart];
		}
		for(j=0;j<n2;j++){
			r[j]=arr[j+middleIndex+1];
		}
		i=0;
		j=0;
		k=leftStart;
		while(i<n1 && j<n2){
			if(l[i]<r[j]){
				arr[k]=l[i];
				i++;
			}
			else{
				arr[k]=r[j];
				j++;
			}
			k++;
		}

		while(i<n1){
			arr[k]=l[i];
			i++;
			k++;
		}
		while(j<n2){
			arr[k]=r[j];
			j++;
			k++;
		}
}

	void mergeSortHelper(int arr[],int l, int r){
		if(l<r){


			int middle=(l+r)/2;
			mergeSortHelper(arr,l,middle);
			mergeSortHelper(arr,middle+1,r);
			mergeArrays(arr, l, middle, r);
		}

	}
	void mergeSort(int arr[],int size){
		int r=size-1;
		int l=0;
		mergeSortHelper(arr,l,r);
	}

};

int main(){
	int arr[]={45,22,112,45,2,3,78,38,1,90};
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	MergeSorter ms;
	ms.mergeSort(arr, 10);

	for(int k=0;k<10;k++){
		cout<<arr[k]<<" ";
	}
	cout<<endl;
}


