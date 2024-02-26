// simple arithmetic on generic class

#include<iostream>
using namespace std;

template <class T>
class arithmetic{
    private:
        T a;
        T b;
    
    public:
        arithmetic();
        arithmetic(T a, T b);
        T add();
        T sub();
        T multiply();
        float division();
};

template <class T>
arithmetic<T>::arithmetic(){
    this->a = 1;
    this->b = 1;
}

template <class T>
arithmetic<T>::arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}

template <class T>
T arithmetic<T>::add(){
    return a+b;
}

template <class T>
T arithmetic<T>::sub(){
    return a-b;
}

template <class T>
T arithmetic<T>::multiply(){
    return a*b;
}

template <class T>
float arithmetic<T>::division(){
    return (float)a/b;
}

int main(){
    float x,y;
    cout<<"enter two numbers: "<<endl;
    cin>>x>>y;
    arithmetic<float> a(x,y);
    cout<<"Addition is: "<<a.add()<<endl;
    cout<<"Sub is: "<<a.sub()<<endl;
    cout<<"Mult is: "<<a.multiply()<<endl;
    cout<<"Division is: "<<a.division();
    return 0;
}
