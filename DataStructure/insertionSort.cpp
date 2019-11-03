#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<chrono>
#include <bits/stdc++.h> 
int main(){
    std::vector<int> elements;
    int size;

    std::cout<<"Enter the size of vector"<<std::endl;
    std::cin>>size;
//    srand(time(0));

    for(int i = 0; i <= size; i++){
        elements.push_back(rand()%1000);
    }

    for(int i = 0; i <= size; i++){
        std::cout<<elements[i]<<"\t";
    }
    std::cout<<""<<std::endl;
    
    auto start = std::chrono::steady_clock::now();
    /* it takes 14.34 ms to sort 1000 elements*/
    int j = 0;
    for(int i = 1; i <= size; i++){
        j = i;
        while(elements[j] < elements[j-1] && j > 0){
            std::swap(elements[j], elements[j-1]);
            j--;
        }
    }

/*  it is taking 8 ms to sort 1000 elements  
    int j = 0;
    int key;
    for(int i = 1; i <= size; i++){
        key = elements[i];
        j = i;
        while(key < elements[j-1] && j > 0){
            elements[j] = elements[j-1];
            j--;
        }
        elements[j] = key;
    }*/
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << "ms" << std::endl;

    for(int i = 0; i <= size; i++){
        std::cout<<elements[i]<<"\t";
    }
    std::cout<<""<<std::endl;
    return 0;
}
