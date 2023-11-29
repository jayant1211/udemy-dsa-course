//finding loop in linked list

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node * first = new node;

bool isLoop(node* p){
    node* ptr1, *ptr2;

    ptr1 = ptr2 = p;

    do{
        //iterations ptr1 by 1 iteration
        ptr1 = ptr1->next;
        //iterate ptr2 by 2 iterations
        ptr2 = ptr2->next;
        ptr2 = (ptr2==NULL)?ptr2:ptr2->next;
        if(ptr1 == ptr2){
            return true;
        }
    }while(ptr1 && ptr2);
    
    return false;
}

void create(node* p,int* arr,int num, int create_loop){
    node* temp;
    node* loop;
    p->data = arr[0];
    for(int i=1;i<num;i++){
        temp = new node;
        temp->data = arr[i];
        temp->next = NULL;
        if(create_loop == i){
            loop = temp;
        }
        p->next = temp;
        p = p->next;
    }
    if(create_loop){
        p->next = loop;
    }
}

void display(node* p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    create(first,arr,7,3);
    //display(first);
    cout<<"Loop: "<<isLoop(first);
    node* second = new node;
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    create(second,arr2,10,0);
    cout<<"Loop: "<<isLoop(second);
}