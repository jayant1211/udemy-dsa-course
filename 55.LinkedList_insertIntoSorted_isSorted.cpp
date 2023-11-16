#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* first = new node;

bool issorted(node* p){
    int min = p->data;
    while(p!=NULL){
        if(min>p->data){
            return false;
        }
        else{
            p = p->next;
        }
    }
    return true;
}

void create(node* p){
    int num;
    cout<<"enter number of elements in linked list: ";
    cin>>num;
    cout<<"enter "<<num<<" elements: ";
    cin>>p->data;
    for(int i=1;i<num;i++){
        node* temp = new node;
        cin>>temp->data;
        temp->next = p->next;
        p->next = temp;
        p = temp;
    }
}

void display(node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

void insert_sorted(node* p, int x){
    //assuming it is sorted
    node *q = new node;
    q = NULL;
    while(p && x>p->data){
        q = p;
        p = p->next;
    }
    node* temp = new node;
    temp->data = x;
    temp->next = p;
    q->next = temp;
}

int main(){
    create(first);
    display(first);
    insert_sorted(first,2);
    cout<<endl;
    display(first);
    cout<<endl;
    cout<<issorted(first);
    node* some_other = new node;
    create(some_other);
    display(some_other);
    cout<<endl;
    cout<<issorted(some_other);
}