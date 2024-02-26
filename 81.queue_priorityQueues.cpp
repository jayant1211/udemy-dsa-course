/**
 * Are to be generated in this cases - 
 * 1. limited set of priorities
 * 2. element priority
*/

/**
 * 1. Limited set of priorites
 * 
 * maintain num of queues equal to number of priorities 
*/

#include<iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;

    void enqueue(int x);
    int dequeue();
    bool is_empty();
    bool is_full();

    queue(int x){
        size = x;
        arr = new int[size];
        front=rear=-1;
    }
    queue(){
        size = 0;
        arr = nullptr;
        front=rear=-1;
    }
    void display();
};

void queue::display(){
    for(int i=front+1;i<=rear;i++) cout<<arr[i]<<" ";
    cout<<endl;
}


void queue::enqueue(int x){
    if(rear==size-1){
        return;
    }
    arr[++rear] = x;
}

int queue::dequeue(){
    if(front==rear){
        cout<<"Queue Empty.";
        return -1;
    }
    int temp = front++;
    arr[front] = -1;
    return temp; //success
}

bool queue::is_empty(){
    if(front==rear)
    return true;
    else return false;
}

bool queue::is_full(){
    if(rear==size-1)
    return true;
    else return false;
}

struct priority_queue{
    int priority_num;
    int size;
    queue* q;

    void enqueue(int x, int priority);
    void dequeue();
    void display();

    priority_queue(int size, int x){
        this->size = size;
        priority_num = x;
        q = new queue[priority_num];
        for(int i=0;i<priority_num;i++) q[i]=queue(this->size);
    }
};

void priority_queue::enqueue(int x, int priority){
    if(!q[priority-1].is_full()) q[priority-1].enqueue(x);
    else cout<<"Queue"<<priority<<" is full."<<endl;
}

void priority_queue::dequeue(){
    int i=0;
    while(q[i].is_empty()!=false){
        i++;
    }
    q[i].dequeue();
}


void priority_queue::display(){
    for(int i=0;i<priority_num;i++){
        cout<<"Queue "<<i+1<<": ";
        q[i].display();
    }
}


int main(){
    priority_queue pq(10,4);
    // Enqueue elements with priorities
    pq.enqueue(1, 1);
    pq.enqueue(2, 2);
    pq.enqueue(3, 1);
    pq.enqueue(4, 3);
    pq.enqueue(5, 1);
    pq.enqueue(6, 2);
    pq.display();
    // Dequeue elements
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.display();
    return 0;
}