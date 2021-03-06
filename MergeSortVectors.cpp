/*
 * MergeSort.cpp
 *
 *  Created on: Nov 3, 2018
 *      Author: samarth
 */
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

class MergeSorter{

public:
	void mergeArrays(vector<int>& arr,int leftStart,int middleIndex, int rightEnd){

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

	void mergeSortHelper(vector<int>& arr,int l, int r){
		if(l<r){


			int middle=(l+r)/2;
			mergeSortHelper(arr,l,middle);
			mergeSortHelper(arr,middle+1,r);
			mergeArrays(arr, l, middle, r);
		}

	}
	void mergeSort(vector<int>& arr,int size){
		int r=size-1;
		int l=0;
		mergeSortHelper(arr,l,r);
	}

};

int main(){
	vector<int> arr;
	for(int i=2000000;i>0;i--){
		arr.push_back(i);
	}

	cout<<endl;
	MergeSorter ms;
	std::chrono::time_point<std::chrono::system_clock> start, end; 	
	start = std::chrono::system_clock::now(); 
	
	ms.mergeSort(arr, arr.size());
	
	end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start; 
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n"; 
	cout<<endl;
}


