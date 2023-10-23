/**
 * toeplitz matrix
| 3  4  7  2  1 |
| 1  3  4  7  2 |
| 2  1  3  4  7 |
| 7  2  1  3  4 |
| 4  7  2  1  3 |

Total elements = n + n-1 = {3,1,2,7,4,4,7,2,1}

*/ 


#include<iostream>
using namespace std;

class lt_matrix{
    int n;
    int *A;
    public:
    lt_matrix(){
        cout<<"Enter dimension: ";
        cin>>n;
        //number of elements - 2n-1
        A = new int[2*n-1];
    }
    void set_all();
     int get(int i, int j);
    void display(); 
    ~lt_matrix(){
        delete []A;
    } 
};

void lt_matrix::set_all(){
    cout<<"Enter "<<2*n-1<<" elements: ";
    for(int i=0;i<2*n-1;i++)
        cin>>A[i];
}

int lt_matrix::get(int i,int j){
    int temp;
    //get element at given index
    if(i>=j){
        //these are stored first - lower(1st column)
        return A[i-j]; 
    } else{
        //these are stored later - upper
        return A[n+j-i-1];
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