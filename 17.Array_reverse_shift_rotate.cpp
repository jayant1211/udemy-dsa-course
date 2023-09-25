#include<iostream>
using namespace std;

class arr{
    private:
        int *A;
        int length, size;
    
    public:
        arr(){
            length = 0;
            size = 0;
        }
        arr(int length, int size){
            this->length = length;
            this->size = size;
            A = new int[size];
            cout<<"Enter "<<length<<" elemets: ";
            for(int i=0;i<this->length;i++)
                cin>>A[i];
        }
        void display();
        void reverse_no_space();
        void reverse_simple();
        void swap(int &a,int &b);
        void left_shift(){
            int i=0;
            for(i=0;i<length-1;i++){
                A[i] = A[i+1];
            }
            A[i] = 0;
            cout<<"Shited Left: ";
            display();
        }
        void left_rotate(){
            int i=0,temp = A[i];
            for(i=0;i<length-1;i++){
                A[i] = A[i+1];
            }
            A[i] = temp;
            cout<<"Rotated Left: ";
            display();
        }
        void right_shift(){
            int i=length-1;
            for(;i>0;i--){
                A[i] = A[i-1];
            }
            A[i] = 0;
            cout<<"Shited Right: ";
            display();
        }
        void right_rotate(){
            int i=length-1,temp = A[i];
            for(;i>0;i--){
                A[i] = A[i-1];
            }
            A[i] = temp;
            cout<<"Rotated Right: ";
            display();
        }
};

void arr::display(){
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
}

void arr::swap(int &a,int &b){
    int temp = b;
    b = a;
    a = temp;
}

void arr::reverse_no_space(){
    for(int i=0,j=length-1;i<j;i++,j--){
        swap(A[i],A[j]);
    }
    cout<<"Reversed without using space: ";
    display();
}

void arr::reverse_simple(){
    //we use temporary array and then copy the elements into prior one
    int *B = new int[length];
    for(int i=length-1,j=0;i>=0;i--,j++){
        B[j] = A[i];
    }
    for(int j=0;j<length;j++)
        A[j] = B[j];
    //free(B);
    delete []B;
    cout<<"Reversed using an temp array: ";
    display();
}

int main(){
    arr a1(8,10);
    a1.reverse_no_space();
    a1.reverse_simple();
    a1.left_shift();
    a1.left_rotate();
    a1.right_shift();
    a1.right_rotate();
}