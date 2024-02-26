#include<iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}

//using reference
/***
 * WHY NOT USE REFERENCE FREQUENTLY 
 * machine code of function is pasted at function call. (may become inline function)
 * not advisable to use for big programs
*/
void swap(int &a,int&b){
    int temp=a;
    a=b;
    b=temp;

    /***
     * swapping without temp variable
     * a = a + b
     * b = a - b
     * x = a - b
    */
}

//using pointers
void swap_using_pointer(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x,y,choice;

    cout<<"Enter First variable: ";
    cin>>x;
    cout<<"Enter Second Variable: ";
    cin>>y;

    cout<<"What do you like to perform:\n1.Sum\n2.Swap"<<endl;
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"Sum is: "<<add(x,y);
        break;
    case 2:
        swap(x,y);
        cout<<"Value of x is: "<<x<<" and of y is: "<<y;
        break;
    default:
        break;
    }
}