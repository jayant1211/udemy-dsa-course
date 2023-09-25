/*
e^x = 1 + x + (x^2/2!) + (x^3/3!) + ... + (x^n/n!)

can have some precision limit like say x^k/k!<=0.000005 then stop adding things
*/
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    } else{
        return n*factorial(n-1);
    }
}
int power(int m,int n){
    if(n==0){
        return 1;
    } else{
        return m*power(m,n-1);
    }
}

long double taylor_expansion(int x){
    static int counter=0;
    long double additive = (long double)power(x,counter)/factorial(counter);
    if(additive<=0.000005){
        return 0;
    } else{
        counter++;
        return additive + taylor_expansion(x);
    }
}

int main(){
    int x;
    cout<<"x: ";
    cin>>x;
    cout<<"answer: "<<taylor_expansion(x);
}
