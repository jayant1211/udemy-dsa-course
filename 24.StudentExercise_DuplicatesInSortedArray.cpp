#include<iostream>
using namespace std;

void duplicates(int *A, int len){
    //3,6,8,8,10,12,15,15,20
    //0,1,2,3, 4, 5, 6, 7, 8
    int i=0,j=1;
    cout<<endl;
    for(;j<len;){
        if(A[i]==A[j]){
            cout<<"Duplicate: "<<A[j++];
            while(A[i]==A[j])
                j++;
            cout<<" occured "<<j-i<<" times"<<endl; 
            i = j -1;
        }
        
        i++;
        j++;
        
    }
}

int main(){
    int len;
    cout<<"Enter len: ";
    cin>>len;
    cout<<"Enter elements: ";
    int *A = new int[len];
    for(int i=0;i<len;i++)
        cin>>A[i];
    duplicates(A,len);
}