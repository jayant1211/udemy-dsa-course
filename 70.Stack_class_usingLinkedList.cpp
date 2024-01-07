#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class stack{
    private:
        int size,curr_size=0;
        node* top = nullptr;
        node *s;
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
}

stack::stack(int size){
    this->size = size;
}

void stack::push(int x){
    if(curr_size==size){
        cout<<"Stack overflow."<<endl;
        return;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = top;
    top = temp;
    curr_size++;
}

void stack::pop(){
    if(curr_size==0){
        cout<<"stack underflow"<<endl;
        return;
    }
    cout<<"Deleted "<<top->data<<endl;
    node* temp = top;
    top = top->next;
    delete temp;
    curr_size--;
}

void stack::display(){
    node* p = top;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();s.pop();s.pop();s.pop();s.pop();s.pop();s.pop();
    s.push(5);
    s.push(6);
    s.push(7);
    s.display();
}