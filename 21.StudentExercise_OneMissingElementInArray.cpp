#include<iostream>
using namespace std;

int singleMissingElementV1(int *A, int len){
    //finding using sum of n natural numbers for sorted array (only one missing)
    int sum_actual=0;

    int sum_expected = ((A[len-1])*(A[len-1]+1))/2 - ((A[0]-1)*(A[0]))/2;
    for(int i=0;i<len;i++){
        sum_actual = sum_actual + A[i];
    }
    return sum_expected - sum_actual;
}

int singleMissingElementV2(int *A, int len){
    //using index
    int diff = A[0]-0;
    for(int i=1;i<len;i++){
        if(diff!=A[i]-i){
            return i+diff;
        }
    }
    return 0;
}

int main(){
    int len;
    cout<<"enter len: ";
    cin>>len;
    int *A = new int[len];
    cout<<"\nenter sorted array with one missing element: ";
    for(int i=0;i<len;i++){
        cin>>A[i];
    }
    cout<<"missing element is: "<<singleMissingElementV1(A,len);
    cout<<"\n";
    cout<<"missing element is: "<<singleMissingElementV2(A,len);
}