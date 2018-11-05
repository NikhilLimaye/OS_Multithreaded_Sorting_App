#include <thread>
#include <iostream>
#include <vector>

using namespace std;


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


void print(vector<int> x)
{
	for(int i = 0 ; i<x.size() ; i++)
	{
		cout<<x[i]<<" ";
	}	
	cout<<endl;
}

void threadmerge(vector<int>& left, vector<int>& right, vector<int>& result)
{
	int i=0,j=0,k=0;
	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
		k++;
	}
		
		while(i<left.size())
		{
			result.push_back(left[i]);
			i++;
			k++;
		}
		
		while(j<right.size())
		{
			result.push_back(right[j]);
			j++;
			k++;
		}

	}


int main()
{
	//vector<int> v1{10,9,8,7,1};
	//vector<int> v1;
	int v1[500000], v2[500000];
	for(int a=500000 ; a>0 ; a--)
	{
		v1[a] = a;
	}
	//vector<int> v2{11,34,44,6,100,55,77};
	//vector<int> v2;
	for(int a=500000 ; a>0 ; a--)
	{
		v2[a] = a+500000;
	}
	//cout<<"Point 1";
	vector<int> result; 
	
	std::chrono::time_point<std::chrono::system_clock> start, end; 	
	start = std::chrono::system_clock::now(); 

	
	thread t1(mergeSort, ref(v1),500000);	
	thread t2(mergeSort, ref(v2),500000);
	t1.join();
	t2.join();
	//cout<<"Point 2";
	vector<int> v11(v1, v1+sizeof(v1)/sizeof(int));
	vector<int> v12(v2, v2+sizeof(v2)/sizeof(int));
	thread t3(threadmerge, ref(v11), ref(v12), ref(result));
	t3.join();
	//cout<<"Point 3";
	end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start; 
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n"; 
	
	//print(result);
	return 0;
}
