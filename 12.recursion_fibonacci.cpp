/*
f(n) = 1,1,2,3,5,8,13

recursive approach:
term f(n) = f(n-1) + f(n-2)
if n<=2:
f(n) = 1
here n is index/term number

time complexity: O(2^n)
*/
#include<iostream>
using namespace std;

void non_recursive(int n);
int recursive(int n);

int main(){
    int n;
    cout<<"n: ";
    cin>>n;
    non_recursive(n);
    cout<<endl;
    for(int i=0;i<=n;i++)
        cout<<recursive(i)<<" ";
}

int recursive(int n){
    if(n<=1){
        return 1;
    } else{
        return recursive(n-1) + recursive(n-2);
    }
}

void non_recursive(int n){
    int prev_=0;
    int prev=1;
    int curr;
    cout<<"1 ";
    while(n--){
        curr  = prev + prev_;
        cout<<curr<<" ";
        prev_ = prev;
        prev = curr;
    }
}
