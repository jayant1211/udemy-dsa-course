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
        char get_top();
};

char stack::get_top(){
    return top->c;
}

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
    return top == nullptr;
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

bool is_balanced2(string s){
    char c=s[0];
    int i =1;
    stack stk;
    while(c!='\0'){
        if(c=='(' || c=='[' || c=='{'){
            stk.push(c);
        } else if(c==')'){
            if(stk.get_top() == '('){
                stk.pop();
            }
            else return false;
        } else if(c=='}'){
            if(stk.get_top() == '{'){
                stk.pop();
            }
            else return false;
        } else if(c==']'){
            if(stk.get_top() == '['){
                stk.pop();
            }
            else return false;
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
    string s2 = "[A+B+(C+D)+{e+F)}]";
    string s3 = "[A+B+(C+D)+{e+F}";
    string s4 = "[A+B+(C+D)+{e+F}]";
    cout<<is_balanced2(s2)<<endl;
    cout<<is_balanced2(s3)<<endl;
    cout<<is_balanced2(s4);
}