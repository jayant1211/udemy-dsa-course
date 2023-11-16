#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* first = new node;

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

void display(node* p){
    cout<<endl;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

node* concatenate(node* &p, node* &q){
    node* curr;
    curr = p;
    while(curr->next){
        curr=curr->next;
    }
    curr->next = q;
    q = nullptr;
    return p;
}

int main(){
    node* second = new node;;
    create(first);
    create(second);
    cout<<"First: ";
    display(first);
    cout<<"Second: ";
    display(second);

    cout<<"Concatenating: ";
    concatenate(first,second);
    display(first);
}