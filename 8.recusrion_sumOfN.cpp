/*

formula based
sum of n natural numbers = n*(n+1)/2 

using recursion

sum of n natural numbers = n + (sum of n-1 natural numbers)

this is descending recursion example

ascending recursion wont return back
descending recursion will come back at starting point
*/

#include<iostream>
using namespace std;

int using_formula(int n){
    return (n*(n+1))/2;
}

int using_recusrion(int n){
    if(n==1){
        return 1;
    }
    else{
        return n + using_recusrion(n-1);
    }
}

int main(){
    int n,choice;
    cout<<"n: "<<endl;
    cin>>n;
    cout<<"1.using formula 2.using recursion: ";
    cin>>choice;
    if(choice==1){
        cout<<using_formula(n);
    }
    else if(choice==2){
        cout<<using_recusrion(n);
    }
    else{
        cout<<"using formula: "<<using_formula(n);
        cout<<endl<<"using recursion: "<<using_recusrion(n);
    }

}