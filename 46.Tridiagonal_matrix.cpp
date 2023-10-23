/**
 * Tridiagonal matrix
| 4  1  0  0  0 |
| 2  6  3  0  0 |
| 0  9  7  5  0 |
| 0  0  2  8  1 |
| 0  0  0  3  4 |

FORMULA :  
Total elements = n + 2*(n-1) = 3n - 2;

storing pattern is up to us, either lower diagonal first, then diagonal and then upper one
or upper-middle-lower

here: upper middle lower
[u,u,u,u,m,m,m,m,m,l,l,l,l]
*/ 

//Either upper or lower traingular matrix will do.

#include<iostream>
using namespace std;

class lt_matrix{
    int n;
    int *A;
    public:
    lt_matrix(){
        cout<<"Enter dimension: ";
        cin>>n;
        //number of elements - 3*n-2
        A = new int[3*n-2];
    }
    void set_all();
     int get(int i, int j);
    void display(); 
    ~lt_matrix(){
        delete []A;
    } 
};

void lt_matrix::set_all(){
    cout<<"Enter "<<3*n - 2<<" elements: ";
    for(int i=0;i<3*n - 2;i++)
        cin>>A[i];
}

int lt_matrix::get(int i,int j){
    int temp;
    //get element at given index
    if(i==j){
        //middle element
        return A[n-1 + i];
    } else if(i-j==1){
        //lower element
        return A[n+n-1+j];
    } else if(j-i==1){
        //upper element
        return A[i];
    } else{
        return 0;
    }
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