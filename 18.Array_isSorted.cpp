#include<iostream>
using namespace std;

class arr{
    int *A;
    int size, length;

    public:
        arr(){
            size = 0;
            length = 0;
        }
        arr(int size, int length){
            this->size = size;
            this->length = length;

            A = new int[size];
            cout<<"Enter "<<length<<" numbers: ";
            for (int i=0;i<length;i++)
                cin>>A[i];
        }
        int get_size(){
            return size;
        }
        int get_length(){
            return length;
        }
        int* get_pointer(){
            return A;
        }
        ~arr(){
            delete[] A;
        }

};

bool isSorted(arr &A){
    int length = A.get_length();
    int *A_pointer = A.get_pointer();

    for(int i=0;i<length-1;i++){
        if(A_pointer[i]>A_pointer[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    arr A(10,5);
    cout<<isSorted(A)<<"\n";
}