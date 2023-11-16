/*
creating linked list using insert operation

*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}*first;

void insert(node* p, int x, int pos){
    if(pos!=0){
        for(int i=0;i<pos-1;i++){
            if(p==NULL){
                cout<<"Cant insert "<<x<<" at "<<pos<<" linked list only has "<<i<<" elements. ENDING"<<endl;

                return;
            }
            else{
                p = p->next;
            }
        }
        node* temp = new node;
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
    }
    else{
        //assuming it is being inserted for the very first time
        first->data = x;
    }
}

void create(node* p){
    int num;
    cout<<"Enter number of elemets in linked list: ";
    cin>>num;
    int x;
    for(int i=0;i<num;i++){
        cout<<"Enter "<<i<<" element: ";
        cin>>x;
        insert(p,x,i);
    }
    cout<<"Completed!\n";
}

void display(node* p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}


int main(){
    first = new node;
    create(first);
    display(first);
}