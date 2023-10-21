/**
 * Diagonal matrix
 * M[i,j] = 0 ;i!=j
 * [1 0 0
 * 0 1 0
 * 0 0 1]
*/
// we only want to store nx elements.

#include<iostream>
using namespace std;

class matrix{
    int n;
    int *A;
    public:
    matrix(int n){
        this->n = n;
        A = new int[n];
    }
    matrix(){
        cout<<"Enter dimension: ";
        cin>>n;
        A = new int[n];
    }
    void set_all();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display(); 
    ~matrix(){
        delete []A;
    } 
};

void matrix::set_all(){
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>A[i];
}

void matrix::set(int i, int j, int x){
    //set element at given index
    if(i==j)
        A[i] = x;
}

int matrix::get(int i,int j){
    //get element at given index
    if(i==j)
        return A[i];
    else
        return 0;
}

void matrix::display(){
    //display matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<get(i,j)<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    matrix m;
    m.set_all();
    m.display();
    cout<<"\nm[5,5]: "<<m.get(4,4);
}