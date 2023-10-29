/***
 * p(x) = 3x^3 + 3x + 4
 * each x has two things - coefficient and exponent;
 * we can maintain a struct likewise
 * 
*/
#include<iostream>
using namespace std;

struct term{
    int c,e;
};

class poly{
    int num;
    term* terms;

    public:
        poly(int num){
            this->num = num;
            terms = new term[num];
        }
        poly(){
            cout<<"enter num pf terms: ";
            cin>>num;
            terms = new term[num];

        }
        void create();
        void display();
        int evaluate(int x);

        ~poly(){
            delete []terms;
        }
        poly operator+(poly &p2);
};

void poly::create(){
    cout<<"Enter "<< num<<" pairs of coefficient and exponent:\n";
    for(int i=0;i<num;i++)
        cin>>terms[i].c>>terms[i].e;      
}

void poly::display(){
    for(int i=0;i<num;i++){
        if(terms[i].e==0)
            cout<<terms[i].c;
        else
            cout<<terms[i].c<<"x^"<<terms[i].e;
        if(i!=num-1)
            cout<<" + ";
    }
}

int poly::evaluate(int x){
    int sum = 0;
    for(int i=0;i<num;i++){
        sum += terms[i].c*(pow(x,terms[i].e));
    }
    return sum;
}

poly poly::operator+(poly &p2){
    int i,j,k;
    i=j=k=0;
    poly result(num + p2.num);
    while(i<num && j<p2.num){
        if(terms[i].e>p2.terms[j].e)
            result.terms[k++] = terms[i++];
        else if(terms[i].e<p2.terms[j].e)
            result.terms[k++] = terms[j++];
        else{
            //equal addition
            result.terms[k] = terms[i++];
            result.terms[k++].c += p2.terms[j++].c;
        }
    }
    result.num = k;
    return result;
}

int main(){
    poly p1(5);
    poly p2(3);
    p1.create();
    p2.create();
    cout<<endl<<"p1(x): ";
    p1.display();
    cout<<endl<<"p2(x): ";
    p2.display();
    
    poly p3 = p1 + p2;
    cout<<"\np1(x) + p2(x) = ";
    p3.display();

    cout<<"\nfor x = 1: "<<p1.evaluate(1);
    cout<<"\nfor x = 2: "<<p1.evaluate(2);
}