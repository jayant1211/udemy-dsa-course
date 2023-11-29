#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* create_circular(int arr[],int num){
    node* head,*last,*temp;
    head=nullptr;
    int i=0;
    while(i<num){
        temp = new node;
        temp->data = arr[i];

        if(head==nullptr){
            head=temp;
            head->next = nullptr;
            last=head;
        } else{
            last->next = temp;
            last = temp;
            last->next = nullptr;
        }
        i++;
    }
    last->next = head;
    return head;
}

void display(node* p){
    node *q=p;
    do{
        cout<<q->data<<" ";
        q = q->next;
    }while(q!=p);
    cout<<endl;
}

node* insert(node *p,int index,int num){
    node* head = p;
    node* temp = new node;
    //0 being at head;
    if(!index){
        //head;
        while(p->next!=head) p=p->next;
        temp->data = num;
        p->next = temp;
        temp->next = head;
        head = temp;
    } else{
        for(int i=0;i<index-1;i++) p=p->next;
        temp->data = num;
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}

int main(){
    int a[] = {1,2,3,4,6};
    node *l1 = create_circular(a,5);
    display(l1);
    l1 = insert(l1,0,5);
    display(l1);
}