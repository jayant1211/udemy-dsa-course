//to handle associaitvity, we use can either use two precedencies (in_stack_precedency, out_stack_precedence)
#include<iostream>
using namespace std;

struct stack{
    stack();
    stack(int x);
    void push(char c);
    char pop();
    bool is_empty();
    char get_top(){
        if(top==-1) return '0';
        else return c[top];
    }
    int size,top=-1;
    char *c;
};

bool stack::is_empty(){
    return top==-1;
}
stack::stack(){
    cout<<"enter size of stack: ";
    cin>>size;
    c = (char *)(malloc(sizeof(char)*size));
}

stack::stack(int x){
    size = x;
    c = (char *)(malloc(sizeof(char)*size));
}

void stack::push(char x){
    if(top==size-1){
        cout<<"stack overflow."<<endl;
    }
    top++;
    c[top]=x;
}

char stack::pop(){
    if(top==-1){
        cout<<"stack underflow.";
    }
    return c[top--];
}

bool is_operand(char c){
    return ((c>=int('a') && c<=int('z')) || (c>=int('A') && c<=int('Z')) || (c>=int('0') && c<=int('9')));
}

//a good rule of thumb while handling R to Left and L to R:
//if R to L in_prec>out_prec;
int out_prec(char c){
    //currently char are out of stack
    if(c=='+' || c=='-') return 1;
    else if(c=='*' || c=='/') return 3;
    else if(c=='^') return 6;
    else if(c=='(') return 7; //inserting ( at all cost
    else if(c==')') return 0; //pull everything out
    else return -1;
}

int in_prec(char c){
    //currently char are inside of stack
    if(c=='+' || c=='-') return 2;
    else if(c=='*' || c=='/') return 4;
    else if(c=='^') return 5;
    else if(c=='(') return 0; //equal rto out )
    else return -1;
}

char* infix_to_postfix(char* infix){
    stack s(strlen(infix));
    char* postfix = (char *)(malloc(sizeof(char)*strlen(infix)));
    int i=0,j=0;

    while(infix[i]!='\0'){
        if(is_operand(infix[i])) postfix[j++]=infix[i++];
        else if(out_prec(infix[i])>in_prec(s.get_top())) s.push(infix[i++]);
        else if(out_prec(infix[i])<in_prec(s.get_top())) postfix[j++] = s.pop();
        else if(out_prec(infix[i])==in_prec(s.get_top())){
            s.pop();
            i++;
        }
    }
    while(!s.is_empty()) postfix[j++]=s.pop();
    postfix[j]=='\0';
    return postfix;
}


int main(){
    char* infix1 = "((a+b)*c)-d^e^f";
    char* postfix = infix_to_postfix(infix1);
    cout<<postfix;
}
