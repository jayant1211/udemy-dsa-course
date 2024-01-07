#include<iostream>

using namespace std;

struct node{
    char c;
    node *next;
};

class stack{
    node *top=nullptr;
    public:
        void pop();
        void push(char c);
        bool is_empty();
};

void stack::pop(){
    if(top == nullptr){
        cout<<"stack undeflow";
        return;
    }
    node *temp = top;
    top = top->next;
    temp->next = nullptr;
    delete temp;
}

void stack::push(char c){
    node *temp = new node;
    if(!temp){
        cout<<"stack overflow.";
        return;
    }
    temp->c = c;
    temp->next = top;
    top = temp;
}

bool stack::is_empty(){
    if(top == nullptr) return true;
    else return false;
}

bool is_balanced(string s){
    char c=s[0];
    int i =1;
    stack stk;
    while(c!='\0'){
        if(c=='('){
            stk.push(c);
        } else if(c==')'){
            stk.pop();
        }
        c=s[i++];
    }
    return stk.is_empty();
}

int main(){
    string s = "( A + B + ( C + D + ( E + F + G ) ) )";
    cout<<is_balanced(s)<<endl;
    string s1 = "(A+B+(C+D+(E+F+G))";
    cout<<is_balanced(s1)<<endl;
}