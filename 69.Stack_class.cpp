#include<iostream>
using namespace std;

class stack{
    private:
        int size;
        int top=-1;
        int *arr;
    public:
        stack();
        stack(int size);
        void push(int x);
        void pop();
        void display();
};

stack::stack(){
    cout<<"Enter size: ";
    cin>>size;
    arr = new int[size];
}

stack::stack(int size){
    size = size;
    arr = new int[size];
}

void stack::push(int x){
    if(top==size-1){
        cout<<"Stack overflow."<<endl;
        return;
    }
    top+=1;
    arr[top]=x;
}

void stack::pop(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"Deleted "<<arr[top]<<endl;
    top-=1;
}

void stack::display(){
    for(int i=top;i>=0;i--) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.push(5);
    s.display();
}