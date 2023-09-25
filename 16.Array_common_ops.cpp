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
        int get_index(int n){
            if(n<length){
                return A[n];
            }
            else return -1;
        }
        void set_index(int index, int n){
            if(index<length) A[index]=n;
            else cout<<"Invalid Index"<<endl;
        }
        int sum(){
            int sum = 0;
            for(int i=0;i<length;i++)
                sum+=A[i];
            return sum;
        }
        int average(){
            int sum = 0;
            for(int i=0;i<length;i++)
                sum+=A[i];
            return sum/length;
        }
        int max(){
            int max = A[0];
            for(int i=1;i<length;i++)
                if(max<A[i]) max = A[i];
            return max;
        }
};

void arr::display(){
    cout<<"Displaying Elements: ";
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
}

int main(){
    arr a1(5,10);
    a1.display();
    cout<<"\n";
    cout<<"Max: "<<a1.max();
    cout<<"\nAverage: "<<a1.average();
    cout<<"\nSum: "<<a1.sum();
    cout<<"\nIndex at 0: "<<a1.get_index(0);
    a1.display();
    cout<<"\n";
    cout<<"\nSetting -100 at index 0: ";
    a1.set_index(0,-100);
    a1.display();
    cout<<"\n";
    cout<<"Max: "<<a1.max();
    cout<<"\nAverage: "<<a1.average();
    cout<<"\nSum: "<<a1.sum();
    cout<<"\nIndex at 0: "<<a1.get_index(0);
}