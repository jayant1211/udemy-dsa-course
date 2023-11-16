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

void reverse(node* p){
    node *prev = NULL;
    node *curr,*temp;

    while(p){
        curr = new node;
        curr->data = p->data;
        curr->next = prev;
        prev = curr;
        temp = p;
        p = p->next;
        delete temp;
    }
    first = curr;
}

void reverse_inplace(node* p){
    node* q = NULL;
    node* temp;
    while(p){
        temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    first = q;
}

void reverse_recursive(node* q, node* p){
    if(p!=NULL){
        reverse_recursive(p,p->next);
        p->next = q;
    } else{
        first = q;
    }
}


int main(){
    create(first);
    display(first);

    reverse(first);
    display(first);

    reverse_inplace(first);
    display(first);

    node* temp = NULL;

    reverse_recursive(temp,first);
    display(first);
}