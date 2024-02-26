/**
 * not necessarily fifo
 * rear can perform - deletion & insetion
 * front can perform - deletion & insertion
 * JAVA Supports this
 * 
 * Variations:
 * Input restricted dequeue:
 * front - delete
 * rear - insert and delete
 * 
 * Output restricted dequeue:
 * front - insert and delete
 * rear - insert
*/

#include<iostream>
using namespace std;

struct dequeue{
    int size;
    int front,rear;
    int *arr;

    void front_insert(int x);
    void rear_insert(int x);
    int front_delete();
    int rear_delete();
    void display();

    dequeue(){
        cout<<"enter size: ";
        cin>>size;
        arr = new int[size];
        front=rear=-1;
    }

    dequeue(int size){
        this->size = size;
        arr = new int[size];
        front=rear=-1;
    }
};

void dequeue::front_insert(int x){
    if(front==-1){
        cout<<"cannot insert. front is at minimum.\n";
        return;
    }
    arr[front--]=x;
}
void dequeue::rear_insert(int x){
    if(rear==size-1){
        cout<<"queue is full";
        return;
    }
    arr[++rear] = x;
}
int dequeue::front_delete(){
    if(front==rear){
        cout<<"queue is empty";
        return -1;
    }
    return arr[front++];
}
int dequeue::rear_delete(){
    if(rear==front){
        cout<<"queue is empty";
        return -1;
    }
    return arr[rear--];
}

void dequeue::display(){
    for(int i=front+1;i<=rear;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    dequeue dq(10);
    dq.front_delete();
    dq.rear_delete();
    for(int i=0;i<10;i++) dq.rear_insert(i);
    dq.display();
    dq.front_delete();
    dq.front_delete();
    dq.display();
    dq.front_insert(1000);
    dq.display();
    dq.rear_delete();
    dq.rear_delete();
    dq.display();
}