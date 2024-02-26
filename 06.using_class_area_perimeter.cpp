//Area and perimeter using class 

#include<iostream>
#include<stdio.h>
using namespace std;

class rectangle{
    int l;
    int b;

    public:
    int area(){
        return l*b;
    }

    int perimeter(){
        return 2*(b+l);
    }

    rectangle(){
        l = 0;
        b = 0;
    }

    rectangle(int len, int breadth){
        b = breadth;
        l = len;
    }
};
int main(){
    rectangle r1(19,2);
    cout<<"Area of r1: "<<r1.area()<<endl;
    cout<<"Perimeter of r1: "<<r1.perimeter();

    int l,b;
    cout<<endl<<"Enter length and breadth: ";
    cin>>l>>b;
    rectangle r2(l,b);

    cout<<"area of r2 is: "<<r2.area()<<endl;
    cout<<"perimeter of r2 is: "<<r2.perimeter()<<endl;

    return 0;
}