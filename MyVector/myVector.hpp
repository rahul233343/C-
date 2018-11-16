#ifndef MY_VECTOR
#define MY_VECTOR

#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class MyVector{
	int size;
	int count;
	int *arr;
public:
	MyVector(){
	
	}
	MyVector(int n){
		count = 0;
		size = n;
		createArray(n);
	}
	~MyVector(){
		//cout<<"Destructor calling"<<endl;
		delete [] arr;
	}
	void createArray(int n){
		arr = new int[n];
	
	}
	int* resize(int *a){
			int *arr1 = new int [size*2];
			std::copy(a, a+size, arr1);
			//std::copy(arr.begin(), arr.end(), arr1.begin());
			delete []a;
			a = arr1;
			arr1 = NULL;
			return a;	
	}
	void push_back(int element){
		if (count < size){
			arr[count] = element;
			count++;
		}
		else{
			//resize(arr); //  it gives pointer double free error
			arr = resize(arr); // it will not why?
			arr[count] = element;
			count++;	
			size = size*2;	
		}	
	}
	void display(){
		for(int i = 0; i< count; ++i)
			cout<<arr[i]<<"\t";
	}
	void pop_back(){
		count--;
		if (count <= (size/2)){
			arr = resize(arr);
			size = size/2;
		}
	}	
	void clear(){
		for(int i=0;i<count;++i){
			arr[i] = 0;
		}
		count = 0;
	}
	void insert(int pos, int val){
		if(count<size){
			count= count +1;
			for (int i = count-1; i >= pos-1; --i ){
				arr[i] = arr[i-1];
			}		
			arr[pos-1]= val;
		}
		else{
			arr = resize(arr);
			size = size*2;
			insert(pos,val);
			
		}
	}	
};
#endif //MY_VECTOR
