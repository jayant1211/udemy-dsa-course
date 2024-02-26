//Arrays cannot be passed by value at all. always pass by address.
#include<iostream>
using namespace std;

void print_array(int A[],int size){ //int A[] is taking it as pointer to array
    for(int i=0;i<size;i++){
        cout<<A[i]<<" ";
    }
}

int * make_array(int size){
    int *p;
    p = (int *)malloc(size*sizeof(int)); //p = new int[size];
    for(int i=0;i<size;i++){
        p[i]=i+1;
    }
    return p;
}

int main(){
    int A[5]={0,1,2,3,4};
    cout<<"Size of A: "<<sizeof(A)/sizeof(int)<<endl;
    print_array(A,5);
    cout<<endl;
    int *p;
    p=make_array(10);
    for(int i=0;i<10 ;i++){
        cout<<p[i]<<" ";
    }
}