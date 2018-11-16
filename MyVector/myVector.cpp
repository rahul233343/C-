#include<iostream>
#include"myVector.hpp"
using namespace std;

int main(){

MyVector vect(2) ;

vect.push_back(1);
vect.push_back(2);
vect.push_back(3);
vect.push_back(4);
vect.push_back(5);
vect.push_back(6);
vect.push_back(7);
vect.push_back(8);
vect.display();
cout<<endl;
vect.pop_back();
vect.pop_back();
vect.pop_back();
vect.pop_back();

vect.display();
cout<<endl;
vect.push_back(9);
vect.push_back(10);
vect.push_back(11);
vect.push_back(12);
vect.display();
cout<<endl;
vect.insert(2, 14);
vect.insert(2, 15);
vect.insert(2, 16);
vect.display();
cout<<endl;
vect.clear();
cout<<"\nClear called !!";
vect.display();
cout<<endl;
}
