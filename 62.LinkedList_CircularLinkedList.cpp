#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};


node* create(int arr[],int num){
    node *head = nullptr;
    node *temp, *last;
    last = head;
    int i=0;
    while(i<num){
        temp = new node;
        temp->data = arr[i];
        if(head == nullptr){
            head = temp;
            head->next = nullptr;
            last = head;
        } else{
            last->next = temp;
            last = temp;
            last->next = nullptr;
        }
        i++;
    } 
    return head;
}

node* create_circular(int arr[],int num){
    node *head = nullptr;
    node *last,*temp;
    int i=0;
    while(i<num){
        temp = new node;
        temp->data = arr[i];
        if(head==nullptr){
            head = temp;
            head->next = nullptr;
            last = head;
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

void display(node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    int a[] = {1,2,3,4,5};
    node *l1,*l2;
    l1 = create(a,5);
    display(l1);
    l2 = create_circular(a,5);
    display(l2);
}