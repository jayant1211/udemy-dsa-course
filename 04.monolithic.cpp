//Area and perimeter 

#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int l=0,b=0;
    cout<<"Enter length and Breadth: ";
    cin>>l>>b;

    int area = l*b;
    int peri = 2*(l+b);

    cout<<"area is: "<<area<<endl;
    cout<<"perimeter is: "<<peri<<endl;

    return 0;
}