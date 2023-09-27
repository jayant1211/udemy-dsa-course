#include<iostream>
using namespace std;

//o(n)
void sumSorted(int k,int *A,int len){
    int i,j;
    i=0;
    j=len-1;
    while(i<j){
        if(A[i]+A[j]==k){
            cout<<A[i++]<<" + "<<A[j++]<<" = "<<k;
            cout<<endl;
        }
        else if(A[i] + A[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
}

int main(){
    int len;
    cout<<"enter len: ";
    cin>>len;
    int *A = new int[len];
    cout<<"enter elements: ";
    for(int i=0;i<len;i++)
        cin>>A[i];
    int k;
    cout<<"enter k: ";
    cin>>k;
    sumSorted(k,A,len);
}