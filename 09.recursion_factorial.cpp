/*
descending factorial
fact_n = n* fact(n-1)
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

int main(){
    int n;
    cout<<"n: "<<endl;
    cin>>n;
    cout<<"factorial: "<<factorial(n);
    return 0;
}