#include<iostream>
using namespace std;

struct node{
    char c;
    node *next;
};

class stack{
    node* top;
    public:
        stack(){
            top = nullptr;
        }
        void push(char c){
            node* temp = new node;
            temp->c = c;
            temp->next = top;
            top = temp;
        }
        char pop(){
            char popped = top->c;
            node* temp = top;
            top = top->next;
            temp->next = nullptr;
            delete temp;
            return popped;
        }
        char get_top(){
            if(top) return top->c;
            else return '1';
        }
        bool is_empty(){
            return top==nullptr;
        }
};

bool is_operand(char c){
    if((c>=int('a') && c<=int('b')) || (c>=int('A') && c<=int('Z')) || (c>=int('0') && c<=int('9'))) return true;
    return false;
}

int prec(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    else return -1; //stack is empty
}

string infix_to_postfix(string s){
    stack stk;
    string postfix;
    int i=0;
    while(s[i]!='\0'){
        if(is_operand(s[i])){
            postfix.push_back(s[i++]);
            continue;
        }
        else if(prec(s[i])>prec(stk.get_top()) || s[i]=='('){
            stk.push(s[i++]);
            continue;
        }
        else if(s[i]==')'){
            while(stk.get_top()!='('){
                postfix.push_back(stk.pop());
            }
            stk.pop();
            i++;
            continue;
        }
        else if(prec(s[i])<=prec(stk.get_top())){
            while(prec(stk.get_top())>=prec(s[i])){
                postfix.push_back(stk.pop());
            }
            stk.push(s[i++]);
        }
    }
    while(!stk.is_empty()){
        postfix.push_back(stk.pop());
    }
    return postfix;
}

int main(){
    string s="(A+B)*(C-D)";
    string s1="((a+b)*c)";
    cout<<infix_to_postfix(s)<<endl;
    cout<<infix_to_postfix(s1);
}