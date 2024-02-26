/**
 * drawback of two pointer approach for creating queue is that 
 * _ _ 1 9 8 10
 *     ^     ^
 *     f     r
 * 
 * the two spaces before front are unused.
 * basically, as we dequeue, the size of the queue gets smaller and smaller
 * making out data structure inefficient
 * 
 * Hence, we use something called as circular queue - 
 * 11 _ 1 9 8 10
 *  ^   ^     
 *  r   f
 * here though, 1 space is left empty to satisfy both -
 * r==f ->empty
 * r%size==f-1 ->full     
*/
#include<iostream>
using namespace std;

struct circular_q{
    int size;
    int front=0;
    int rear=0;
    int* arr;
};  

void enqueue(circular_q &c,int x){
    if((c.rear+1)%(c.size+1)==c.front){
        cout<<"Queue is full.";
        return;
    }
    c.rear = (c.rear+1)%(c.size+1);
    c.arr[c.rear] = x;
}

int dequeue(circular_q &c){
    int x=-1;
    if(c.front==c.rear){
        cout<<"queue is empty.";
        return x;
    }
    c.front = (c.front+1)%(c.size+1);
    x = c.arr[c.front];
    return x;
}

void display(circular_q &c){
    int i=c.front+1;
    while(i!=c.rear+1){
        cout<<c.arr[i++]<<" ";
    }
    cout<<endl;
}

int main(){
    circular_q c;
    cout<<"enter size of the queue: ";
    cin>>c.size;
    c.arr = new int[c.size+1];
    dequeue(c);
    cout<<endl;
    for(int i=0;i<10;i++) enqueue(c,i);
    display(c);
    for(int i=0;i<3;i++) dequeue(c);
    display(c);
}