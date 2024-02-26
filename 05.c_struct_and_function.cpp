//Area and perimeter using structure and functions 

#include<iostream>
#include<stdio.h>
using namespace std;

struct rectangle{
    int l;
    int b;
};

int area(rectangle r){
    return r.l*r.b;
}

int perimeter(struct rectangle r){
    return 2*(r.b+r.l);
}

void init(rectangle *r,int l, int b){
    r->b = b;
    r->l = l;
}

int main(){
    rectangle r1 = {10,5};
    cout<<"Area of r1: "<<area(r1)<<endl;
    cout<<"Perimeter of r1: "<<perimeter(r1);

    rectangle r2;
    int l,b;
    cout<<endl<<"Enter length and breadth: ";
    cin>>l>>b;
    init(&r2,l,b);

    cout<<"area of r2 is: "<<area(r2)<<endl;
    cout<<"perimeter of r2 is: "<<perimeter(r2)<<endl;

    return 0;
}