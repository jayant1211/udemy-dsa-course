#include<iostream>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
};

node* create(int arr[],int num){
    node* head,*last,*temp;
    head=nullptr;
    for(int i=0;i<num;i++){
        temp = new node;
        temp->data = arr[i];
        if(head==nullptr){
            head=temp;
            head->prev = nullptr;
            head->next = nullptr;
            last = head;
        } else{
            temp->prev = last;
            last->next = temp;
            last = temp;
            last->next = nullptr;
        }
    }
    return head;
}

node *insert(node *p, int num, int index){
    node* head = p;
    node *temp;
    if(!index){
        //at head
        temp = new node;
        temp->data = num;
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head=temp;
    } else{
        //not head
        for(int i=0;i<index-1;i++) p=p->next;
        temp=new node;
        temp->data = num;
        temp->prev=p;
        temp->next=p->next;
        p->next->prev = temp;
        p->next = temp; 
    }
    return head;
}

node* delete_dll(node* p,int index){
    node *head = p,*temp;
    if(!index){
        temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    } else{
        for(int i=0;i<index-1;i++) p=p->next;
        temp = p->next;
        p->next->next->prev = p;
        p->next = p->next->next;
        
        delete temp;
    }
    return head;
}

node* reverse(node *p){
    node *head = p,*temp;
     
    do{
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }while(p);
    head = temp->prev;
    return head;
}

void display(node* p){
    while(p){
        cout<<"Prev: "<<((p->prev)?(p->prev->data):NULL);
        cout<<"\tCurr: "<<p->data;
        cout<<"\tNext: "<<((p->next)?(p->next->data):NULL);
        cout<<endl;
        p=p->next;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    node* l = create(arr,6);
    display(l);
    l = insert(l,9,0);
    cout<<"after insetion: \n";
    display(l);
    l = delete_dll(l,2);
    cout<<"after deletion: \n";
    display(l);
    cout<<"after reversing: \n";
    l = reverse(l);
    display(l);
}