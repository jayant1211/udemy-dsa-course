#include<iostream>
using namespace std;

struct rectangle
{
    int l,b;
};

//Structures containing array can still be passed as value(arrays alone cant be passed as value)
struct some_s{
    int a[4]={1,2,3,4};
    int b=100;
};

void modify_array(some_s &s){
    s.a[1]=100;
    for(int x:s.a)
    cout<<x<<" ";
}

int area_cbv(struct rectangle r1){
    return r1.l*r1.b;
}

int area_cbr(rectangle &r3){
    return r3.b*r3.l;
}

void increase_by(struct rectangle *r2,int size){
    r2->l = r2->l+size;
    r2->b = r2->b+size;
}

int main(){
    rectangle r1 = {10,5};
    cout<<"Area is: "<<area_cbv(r1)<<endl;

    increase_by(&r1,5);

    cout<<"Area is: "<<area_cbr(r1)<<endl;

    some_s s1;
    //s1.b=5;
    modify_array(s1);
    cout<<endl<<s1.b;
}