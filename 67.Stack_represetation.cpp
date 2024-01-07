/**
 * stack as abstract data type
 * 
 * Works on LIFO Principle
 * 
 * has functions - 
 * 1. push()
 * 2. pop()
 * 3. peek(index)
 * 4. stack_top()
 * 5. is_empty()
 * 6. is_full()
 * 
 * can be implemented using arrays or using linked list
 * 
*/

//USING ARRAY
#include<iostream>
using namespace std;

struct node{
    int size;
    int top = -1;
    int *arr;
};


void push(node &n,int x){
    if(n.top == n.size-1)
        cout<<"Stcak Overflow."<<endl;

    else{
        n.top += 1; 
        n.arr[n.top] = x;
        cout<<"Pushed."<<endl;
    }
}

void pop(node &n){
    cout<<"Poped "<<n.arr[n.top]<<endl;
    n.top--;
}

int peek(node &n, int index){
    /**
     * 0 = top
     * 1 = top-1
     * 2 = top-2
     * i = top - i
    */
   return n.arr[n.top - index];
}

int stack_top(node &n){
    return n.arr[n.top];
}

bool is_stackempty(node &n){
    if(n.top==0)
        return true;
    else return false;
}

bool is_stack_full(node &n){
    if (n.top == n.size -1) return true;
    else return false;
}

void display(node &n){
    for(int i=n.top;i>=0;i--){
        cout<<n.arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    node n;

    cout<<"Enter max size of stack: ";
    cin>>n.size;

    n.arr = new int[n.size];

    push(n,5);
    push(n,6);
    display(n);
    pop(n);
    push(n,16);
    display(n);
    cout<<peek(n,1)<<endl;
    cout<<is_stackempty(n)<<endl;
    cout<<is_stack_full(n)<<endl;
    delete[] n.arr;
}
