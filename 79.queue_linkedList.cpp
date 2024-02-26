#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct queue{
    int size;
    node* front=nullptr;
    node* rear=nullptr;
};

void enqueue(queue &q,int x){
    node *temp = new node;
    if(!temp){
        cout<<"heap is full."<<endl;
    }
    temp->data=x;
    temp->next=nullptr;
    if(q.front==nullptr){
        q.front = temp;
        q.rear =temp;
    }
    else{
        q.rear->next = temp;
        q.rear = temp;
    }
}

int dequeue(queue &q){
    if(q.front==nullptr){
        cout<<"queue empty."<<endl;
        return -1;
    }
    int x=q.front->data;
    q.front = q.front->next;
    return x;
}

void display(queue &q){
    node* p = q.front;
    if(p==nullptr){
        cout<<"queue is empty";
        return;
    }
    while(p!=nullptr){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    queue q;
    enqueue(q,1);
    
    display(q);
    for(int i=0;i<19;i++) enqueue(q,2*i);
    display(q);

    for(int i=0;i<20;i++){
        dequeue(q);
    }
    cout<<"q: ";
    display(q);
}