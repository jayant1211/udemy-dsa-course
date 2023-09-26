#include<iostream>
using namespace std;

void multipleMissingElements(int *A, int len){
    // sorted
    int diff = A[0];
    for(int i=0;i<len;i++){
        if(A[i]-i!=diff){
            while(A[i]-i!=diff){
                cout<<diff+i<<" is missing\n";
                diff++;
            }
        }
    }
}

int main(){
    int len;
    cout<<"enter len: ";
    cin>>len;
    int *A = new int[5];
    for(int i=0;i<len;i++)
        cin>>A[i];
    multipleMissingElements(A,len);
}