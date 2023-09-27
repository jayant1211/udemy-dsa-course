#include<iostream>
using namespace std;

//O(n^2)
void sumV1(int k,int *A, int len){
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(A[i]+A[j]==k){
                cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            }
        }
    }
}

//O(n) - hash Table
void sumV2(int k, int *A, int len){
    int max = A[0];
    for(int i=1;i<len;i++)
        if(max<A[i])
            max = A[i];

    int *res = new int[max+1];
    for(int i=0;i<len;i++){
        if(res[k-A[i]]!=0){
            cout<<A[i]<<" + "<<k-A[i]<<" = "<<k;
        }
        res[A[i]]++;
    }
    delete []res;
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
    sumV1(k,A,len);
    cout<<"\nusing V2: ";
    sumV2(k,A,len);
}