#include<iostream>
using namespace std; 

class rectangle{
    //data members
    //these are private by default
    int l,b;

    public:
    //methods
    //default  constructor
    rectangle();

    //parameterized constructor
    rectangle(int x,int y);

    //facilitators
    int area();
    int perimeter();

    //getters - accessors
    int get_length();
    int get_breadth();

    //setters - mutators
    void set_length(int x);

    void set_breadth(int y);

    //destructor
    ~rectangle();
};

rectangle::rectangle(){
    l=0;
    b=0;
}
rectangle::rectangle(int x,int y){
    l=x;
    b=y;
}
int rectangle::area(){
    return l*b;
}
int rectangle::perimeter(){
    return 2*(l+b);
}
int rectangle::get_breadth(){
    return b;
}
int rectangle::get_length(){
    return l;
}
void rectangle::set_length(int x){
    l=x;
}
void rectangle::set_breadth(int y){
    b=y;
}

//if we have any dynamic memory, can free that thing here; delete arr[]; free(arr)
rectangle::~rectangle(){}

int main(){
    rectangle r1;
    rectangle r2(10,5);

    cout<<"Area of r1: "<<r1.area()<<endl;
    cout<<"Perimeter of r1: "<<r1.perimeter()<<endl;

    cout<<"current length of r1: "<<r1.get_length()<<" \nand current breadth is: "<<r1.get_breadth()<<endl;
    int a,b;
    cout<<"Enter New length and breadth: ";
    cin>>a>>b;

    r1.set_length(a);
    r1.set_breadth(b);

    cout<<"Now\n";
    cout<<"current length of r1: "<<r1.get_length()<<" \nand current breadth is: "<<r1.get_breadth()<<endl;

    cout<<"Area of r1: "<<r1.area()<<endl;
    cout<<"Perimeter of r1: "<<r1.perimeter()<<endl;

    return 0;
}