/**
 * Lower triangular matrix - COLUMN MAJOR
 * M[i,j] = nz ;i<=j
 * [1 0 0 0 0 
 * 1 1 0 0 0
 * 1 1 1 0 0
 * 1 1 1 1 0
 * 1 1 1 1 1]
*/
// we only want to store nz elements.

#include<iostream>
using namespace std;

class lt_matrix{
    int n;
    int *A;
    public:
    lt_matrix(){
        cout<<"Enter dimension: ";
        cin>>n;
        //number of elements - n*(n+1)/2
        A = new int[n*(n+1)/2];
    }
    void set_all();
     int get(int i, int j);
    void display(); 
    ~lt_matrix(){
        delete []A;
    } 
};

void lt_matrix::set_all(){
    cout<<"Enter "<<n*(n+1)/2<<" elements: ";
    for(int i=0;i<n*(n+1)/2;i++)
        cin>>A[i];
}

 

int lt_matrix::get(int i,int j){
    //get element at given index
    if(i>=j)
        return A[j*n - (j*(j-1)/2) + i-j];
    else
        return 0;
}

void lt_matrix::display(){
    //display matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<get(i,j)<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    lt_matrix m;
    m.set_all();
    m.display();
}