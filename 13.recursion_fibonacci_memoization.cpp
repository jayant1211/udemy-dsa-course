/*
in previous code, f(n-1) + f(n-2) will cause a tree recursion, for n=3, we will get f(2) and f(1), then for n=4, we will need to calculate f(3) and again f(2).
can be helpful if we can store f(2) value somewhere

time complexity: O(n)
space complexity: O(n)
*/
#include<iostream>
using namespace std;

int memoization(int n,int *arr){
    if(n<=1){
        arr[n]=1;
        return arr[n];
    } else{
        if(arr[n]==0){
            arr[n] = memoization(n-1,arr) + memoization(n-2,arr);
        }
        return arr[n];
    }
}

int main(){
    int n;
    cout<<"number of terms: ";
    cin>>n;
    int *arr = (int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++)
        cout<<memoization(i,arr)<<" ";
    
    free(arr);
}