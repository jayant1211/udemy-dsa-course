#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* first = new node;

void remove_duplicates(node* p){
    node* q=p;
    p = p->next;

    while(p){
        if(p->data != q->data){
            q = p;
            p = p->next;
        } else{
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}

void remove_duplicates_single_pointer(node *p){
    while(p->next){
        if(p->data!=(p->next)->data){
            p = p->next;
        } else{
            //delete p->next;
            p->next = (p->next)->next;
        }
    }
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
    cout<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    create(first);
    display(first);

    remove_duplicates_single_pointer(first);
    display(first);
}