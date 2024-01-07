#include<iostream>

using namespace std;


struct node{
    node* next;
    int data;
};

//node* first = new node;

node* create(int* arr, int num){
    node* head = new node;
    node* temp;
    node* last = head;
    head->data = arr[0];

    head = last;
    for(int i=1;i<num;i++){
        temp = new node;
        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }

    return head;
}

void display(node *head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void find_middle(node* head){
    //finding middle
    node* p1,*p2;
    p1=p2=head;

    while(p2->next){
        p1=p1->next;
        p2=p2->next;
        if(p2->next) p2=p2->next; 
    }
    cout<<"Middle element is: "<<p1->data;
}

int main(){
    int arr[] = {1,2,3,4,5,50,16,17,18,91};
    int arr2[] = {12,2,3,5};
    node* list2 = create(arr2,4);
    node* list1 = create(arr,10);
    display(list1);
    find_middle(list1);

}