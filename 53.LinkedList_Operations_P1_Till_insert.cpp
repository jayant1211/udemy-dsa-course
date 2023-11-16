/*
DISPLAY  - done
R-DISPLAY - done
COUNTINF NODES  - done
SUM OF ELEMENTS + RECUSRSIVE APPROACH - done
MAX OF LL + RECURSIVE APPROACH - done (slight confusion in rmax)
SEARCHING + RECURSIVE APPROACH - done
IMPROVED SEARCHING - move to head - done
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
}*first = NULL;

node* create(int A[], int num){
    first = new node;
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

void display(node *first){
    node* temp = first;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void rdisplay(node *first){
    if(first->next!=NULL){
        cout<<first->data<<" ";
        rdisplay(first->next);
    }
    else
        cout<<first->data;
}

int count_nodes(node* first){
    node* temp = first;
    int i=0;
    while(temp!=NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

int sum(node* first){
    node* temp = first;
    int sum=0;
    while(temp!=NULL){
        sum+=temp->data;
        temp = temp->next;
    }
    return sum;
}

int rsum(node* first){
    if(first->next==NULL)
        return first->data;
    else
        return first->data + rsum(first->next);
}

int max(node *first){
    int maximum=-1;
    node *temp = first;
    while(temp!=NULL){
        if(maximum<temp->data){
            maximum = temp->data;
        } 
        temp = temp->next;
    }
    return maximum;
}

int rmax(node *first){
    int x = 0;
    if(first==0)
        return 0;
    x = rmax(first->next);
    if(x<first->data)
        return first->data;
    else
        return x;
}

void search(node* first, int x){
    node* temp = first;
    while(temp!=NULL){
        if(temp->data == x){
            cout<<"found "<<x;
            return;
        }
        temp = temp->next;
        
    }
    cout<<"Not present";
}

void rsearch(node *n, int x){
    if(n == NULL){
        cout<<"not present";
        return;
    }
    if(x == n->data){
        cout<<"found "<<x;
        return;
    }
    else{
        rsearch(n->next,x);
    }
}

void move_to_head_search(node* &first, int x){
    node *temp = first;
    node *back=NULL;
    while(temp!=NULL){
        if(temp->data!=x){
            //increment both
            temp = temp->next;
            if(back == NULL){
                back = first;
            } else {
                back = back->next;
            }
        }
        else{
            //data is found, remove that node and make it point at first, make back point at next node prior to this
            back->next = temp->next;
            temp->next = first; // first becomes second
            first = temp; // temp becomes first
            //stop
            break;
        }
    }
    if(temp==NULL)
            cout<<x<<" not found.";
    else{
        cout<<x<<" found.";
        cout<<"\nhere: ";
        display(first);
    }
}

void insert(node* &first, int x, int pos){
    node* t = new node;
    t->data = x;
    if(pos==0){
        //at first node
        t->next = first;
        first = t; 
    }
    else{  
        //we should be at pos -1 node
        node* p = first;
        for(int i=0;i<pos -1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    first = create(A,9);
    cout<<"displaying: "<<endl;
    display(first);
    cout<<"\ndisplaying using recursive function: "<<endl;
    rdisplay(first);
    cout<<"\nCount Nodes:\n"<<count_nodes(first);
    cout<<"\nSum:\n";
    cout<<sum(first);
    cout<<"\nRecursive sum:\n";
    cout<<rsum(first);
    cout<<"\nmaximum:\n";
    cout<<max(first);
    cout<<"\nrmax:\n";
    cout<<rmax(first);
    cout<<"\nSearch:\n";
    search(first,7);
    cout<<"\nrecusrsive search:\n";
    rsearch(first,90);
    cout<<"\nmove to head: \n";
    move_to_head_search(first,7);
    cout<<endl;
    cout<<"ojbfkjbwf"<<first->data;
    insert(first,100,0);
    display(first);
    cout<<endl;
    insert(first,999,5);
    cout<<endl;
    display(first);
}