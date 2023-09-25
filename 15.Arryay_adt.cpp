#include<iostream>
using namespace std;

struct arr{
    int size, length;
    int *A;

    arr(){
        size = 0;
        length = 0;
    }
    arr(int size,int length){
        this->size = size;
        this->length = length;
        A = new int[size];
        cout<<"Enter "<<length<<" elements: ";
        for(int i=0;i<length;i++)
            cin>>A[i];
    }
    void disaply(){
        cout<<"Displaying array: "<<endl;
        for(int i=0;i<length;i++)
            cout<<A[i]<<" ";
    }
    void append(int num){
        if(length <= size)
            A[length++] = num;
        else
            cout<<"Max Size Limit Reached."<<endl;
    }
    void swap(int &a, int &b){
        int temp = b;
        b = a;
        a = temp;
    }
    void insert(int index,int num){
        if(index<=length){
            A[length++] = num;
            for(int i=length-1;i>index;i++)
                swap(A[i],A[i-1]);
        }
    }
    void delete_element(int index){
        cout<<"Deleting index at: "<<index<<endl;
        if(index<length){
            length--;
            for(int i=index;i<length;i++)
                A[i]=A[i+1];
            return;
        }
        cout<<"Invalid index"<<endl;
    }
    void delete_num(int num){
        int counter = 0;
        cout<<"Deleting "<<num<<" :\n";
        for(int i=0;i<length;i++){
            if(A[i] == num){
                delete_element(i);
                i--;
                counter++;
            }
        }
        cout<<"Deleted "<<counter<<" numbers.\n";
    }
    void linear_search(int num){
        for(int i=0;i<length;i++){
            if(A[i] == num){
                cout<<"found at: "<<i<<endl;
            }
        }
    }
};

void binary_search(int l,int h, int *A, int num){
        while(h>=l){
            int m = (l + h)/2;
            if(num==A[m]){
                cout<<"Found "<<num<<" at index "<<m<<endl;
                return;
            }
            else if(num>A[m]){
                l = m+1;
            }
            else if(num<A[m]){
                h = m-1;
            }
        }
        if(h<l){
            cout<<"Element not present in the array."<<endl;
        }
}

int main(){
    arr a1(10,9);
    binary_search(0,a1.length,a1.A,5);

    return 0;
}