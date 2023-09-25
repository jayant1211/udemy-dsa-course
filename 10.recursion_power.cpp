/*
again descending recusrsion
a^x = a * a^x-1
*/

#include<iostream>
using namespace std;

int power(int m,int n){
    if(n==0){
        return 1;
    } else{
        return m*power(m,n-1);
    }
}

int main(){
    int m,n;
    cout<<"m,n: ";
    cin>>m>>n;
    cout<<"factorial: "<<power(m,n);
}