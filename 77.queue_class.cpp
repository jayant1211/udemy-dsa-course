#include<iostream>
using namespace std;

template <typename T> class queue{
    private:
        int size;
        int front;
        int rear;
        T *arr;

    public:
        queue(){
            front=rear=-1;
            size=10;
            arr = new T[size];
        }
        queue(int size){
            this->size=size;
            front = rear =-1;
            arr = new T[this->size];
        }
        void enqueue(T x);
        T dequeue();
        bool is_full();
        bool is_empty();
        void display();
};

template<typename T> void queue<T>::enqueue(T x){
    if(rear==size-1){
        cout<<"queue is full.";
        return;
    }
    arr[++rear] = x;
}

template<typename T> T queue<T>::dequeue(){
    if(front==rear){
        cout<<"queue is empty.";
        return -1;
    }
    return arr[++front];
}

template<typename T> void queue<T>::display(){
    for(int i=front+1; i<=rear; i++) cout<<arr[i]<<" ";
}

template<typename T> bool queue<T>::is_empty(){
    return front==rear;
}

template<typename T> bool queue<T>::is_full(){
    return rear==size-1;
}

int main(){
    queue<float> q(5);
    q.dequeue();
    cout<<endl;
    for(float i=0.1;i<=4.5;i++) q.enqueue(i);
    q.display();
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(10000);
    q.display();

    cout<<"is full: "<<q.is_full();
    cout<<"\nis empty: "<<q.is_empty();
}