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

int* mergeArray(arr &a1,arr &a2){
    int size = a1.get_size() + a2.get_size();
    int length = a1.get_length() + a2.get_length();
    int* A = new int[size];
    int i,j,k;

    for(i=0,j=0,k=0;i<a1.get_length() && j<a2.get_length();){
        if(a1.get_pointer()[i] >= a2.get_pointer()[j]){
            A[k++] = a2.get_pointer()[j++];
        } else{
            A[k++] = a1.get_pointer()[i++];
        }
    }
    for(;i<a1.get_length();i++){
        A[k++] = a1.get_pointer()[i];
    }

    for(;j<a2.get_length();j++){
        A[k++] = a2.get_pointer()[j];
    }
    A[k] = -1;
    return A;
}

int main(){
    arr A(10,5);
    arr B(8,4);
    int *C;
    int i=0;
    C = mergeArray(A,B);
    while(C[i]!=-1){
        cout<<C[i++]<<" ";
    }
}