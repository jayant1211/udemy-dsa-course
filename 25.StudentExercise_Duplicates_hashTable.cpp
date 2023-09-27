#include<iostream>
using namespace std;

void duplicate(int *A,int len){
    int *table = new int[A[len-1]];
    fill(table,table+len,0);
    for(int i=0;i<len;i++){
        table[A[i]]+=1;
    }
    for(int i=0;i<A[len-1];i++){
        if(table[i]>1){
            cout<<i<<" is duplicated "<<table[i]<<" times\n";
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
    duplicate(A,len);
}