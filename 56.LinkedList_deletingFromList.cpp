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

void display(node *p){
    cout<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void delete_node(node* p,int index){
    if(index==0){
        //deleting first node
        cout<<"deleting "<<p->data<<" at "<<index;
        first = p->next;
        delete p;
    } else{
        node* q;
        for(int i=0;i<index;i++){
            if(p!=NULL){
                q = p;
                p = p->next;
            } else{
                cout<<"Index out of range.";
                return;
            }
        }
        cout<<"deleting "<<p->data<<" at "<<index;
        q->next = p->next;
        delete p;
    }
}


int main(){
    create(first);
    display(first);

    //delete
    delete_node(first,10);

    display(first);

    delete_node(first,3);

    display(first);
}