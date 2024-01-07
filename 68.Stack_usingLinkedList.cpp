#include<iostream>
using namespace std;

struct node{
    int data;
    node* prev;
};

struct stack{
    int size;
    node* top=nullptr;
    int curr = 0;
};

void push(stack &s,int x){
    if(s.size==s.curr){
        cout<<"Stack Overflow."<<endl;
        return;
    }
    node *temp = new node;
    temp->data = x;
    temp->prev = s.top;
    s.top = temp;
    s.curr++;
}

void pop(stack &s){
    node* temp = s.top;
    cout<<"popped: "<<s.top->data;
    s.top = s.top->prev;
    
    delete temp;
    cout<<endl;
}

void display(stack &s){
    node *p=s.top;
    while(p){
        cout<<p->data<<" ";
        p = p->prev;
    }
    cout<<endl;
}

int main(){
    stack s;
    cout<<"Enter maximum size of stack: ";
    cin>>s.size;
    push(s,6);
    push(s,0);
    display(s);
    pop(s);
    display(s);
}