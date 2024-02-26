#include<iostream>
using namespace std;

struct queue{
    int size;
    int front=-1;
    int rear=-1;
    int *p; //dynamic array
};

void enqueue(queue &q, int x){
    if(q.rear==q.size-1){
        cout<<"queue is full. ";
        return;
    }
    q.p[++q.rear] = x;
}

int dequeue(queue &q){
    if(q.front==q.rear){
        cout<<"queue is empty. ";
        return -1;
    }
    q.front++;
    return q.p[q.front];
}

void display(queue &q){
    for(int i=q.front+1; i<=q.rear;i++) cout<<q.p[i]<<" ";
}

int main(){
    queue q;
    cout<<"enter size of queue: ";
    cin>>q.size;

    q.p = new int[q.size];
    dequeue(q);
    enqueue(q,10);
    enqueue(q,20);
    cout<<"queue: ";
    display(q);
    dequeue(q);
    enqueue(q,30);
    for(int i=1;i<10;i++) enqueue(q,i);
    cout<<"queue: ";
    display(q);
}