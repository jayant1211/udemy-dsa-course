#include<iostream>
using namespace std;

void min_and_max(int *A,int len){
    int min,max;
    min = A[0];
    max = A[0];
    for(int i=1;i<len;i++){
        if(A[i]>max){
            max = A[i];
        }
        else if(A[i]<min){
            min = A[i];
        }
    }
    cout<<"min: "<<min<<" max: "<<max;
}

int main(){
    int len;
    cout<<"Enter len: ";
    cin>>len;
    int *A = new int[len];
    cout<<"enter elements: ";
    for(int i=0;i<len;i++)
        cin>>A[i];
    
    min_and_max(A,len);
}