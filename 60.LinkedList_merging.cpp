#include<iostream>
using namespace std;
 
struct node{
    int data;
    node* next;
};

node* create(int A[], int num){
    node* first = new node;
    first->data = A[0];
    node *temp,*last;
    last = first;
    for(int i=1;i<num;i++){
        temp = new node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return first;
}

node* merge(node* p, node* q){
    node* head=NULL;
    node* tail=NULL;
    
    while(p && q){
        if(p->data <= q->data){
            if(head==NULL){
                head=tail=p;
                p=p->next;
            } else{
                tail->next=p;
                tail=p;
                p=p->next;
                tail->next=NULL;
            }
        } 
        else{
            if(head==NULL){
                head=tail=q;
                q=q->next;
            } else{
                tail->next=q;
                tail=q;
                q=q->next;
                tail->next=NULL;
            }
        }
    }
    while(p){
        tail->next = p;
        tail = p;
        p = p->next;
        tail->next = NULL;
    }
    while(q){
        tail->next = q;
        tail = q;
        q = q->next;
        tail->next = NULL;
    }
    return head;
}   

void display(node* p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    int a[] = {1,5,8,11};
    int b[] = {2,3,5,9};
    node* first = create(a,4);
    cout<<"first: ";
    display(first);
    node* second = create(b,4);
    cout<<"second: ";
    display(second);
    node* merged = merge(first,second);

    cout<<"merged: ";
    display(merged);
}