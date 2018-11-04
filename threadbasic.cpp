#include <thread>
#include <iostream>
#include <vector>

using namespace std;


void threadsort(vector<int> &v)
{
	int index,value;
	
	for(int i=1 ; i<v.size() ; i++)
	{
		index = i;
		value = v[i];
		
		while(index>0 && (v[index-1]>value))
		{
			v[index] = v[index-1];
			index = index -1;
		}
		v[index] = value;		
	}
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
	vector<int> v1;
	for(int a=50000 ; a>0 ; a--)
	{
		v1.push_back(a);
	}
	//vector<int> v2{11,34,44,6,100,55,77};
	vector<int> v2;
	for(int a=100000 ; a>50000 ; a--)
	{
		v2.push_back(a);
	}
	
	vector<int> result; 
	
	std::chrono::time_point<std::chrono::system_clock> start, end; 	
	start = std::chrono::system_clock::now(); 

	
	thread t1(threadsort, ref(v1));	
	thread t2(threadsort, ref(v2));
	t1.join();
	t2.join();
	
	thread t3(threadmerge, ref(v1), ref(v2), ref(result));
	t3.join();
	
	end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start; 
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n"; 
	
	//print(result);
	

	return 0;
}
