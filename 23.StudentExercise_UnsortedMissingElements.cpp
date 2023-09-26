#include<iostream>
using namespace std;

void missingElements(int *A, int len){
    int max = A[0];
    int min = A[0];
    for(int i=1;i<len;i++){
        if(max<A[i]){
            max = A[i];
        }
        if(min>A[i]){
            min=A[i];
        }
    }
    
    int*hashMap = new int[max]; 
    fill(hashMap, hashMap + max, 0);
    
    for(int i=0;i<len;i++){
        cout<<A[i]<<" "; 
        hashMap[A[i]] = 1;
    }
    cout<<endl;
    for(int i=min;i<max;i++){
        if(hashMap[i]==0)
            cout<<i<<" is missing\n";
    }


}

int main(){
    int len;
    cout<<"Enter len: ";
    cin>>len;
    int *A = new int[len];
    cout<<"enter elements: ";
    for(int i=0;i<len;i++)
        cin>>A[i];
    
    missingElements(A,len);
}