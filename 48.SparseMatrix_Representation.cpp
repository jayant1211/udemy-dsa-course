/***
 * sparse matrix is a matrxi which has higher number of zeros
 * rules of thumb is 2/3rd of elements in sparse matrix are 0
 * we need to save space so we will only store non-zero elements
 * 
 * M = 
 * |1 0 0 0 0|
 * |2 1 0 0 0|
 * |0 0 0 0 1|
 * |0 0 0 0 0|
 * |1 0 0 0 1|
 * |6 0 0 1 0|
 * 
 * two approach
 * 
 *1.Coordinate list or 3 column representation
 and 
 *2.Compressed Sparse Row

 coordinate list - 
 |m,n,num|
 |i,j,ele|
 |i,j,ele|
 .
 .
 .
 |i,j,ele|

 compressed sparse row
 num_of_ele_in_row-[0 1 3 4 6 8 9] //contains how many number of elements are there in each row, cumulative sum of num
 column - [0 1 1 2 3 1 7 9] // which colum they belong to
 elem - [1 8 4 3 6 2 3 6]  
*/

//COORDINATE LIST

#include<iostream>
using namespace std;


struct ele{
    int i,j; //rows and columns
    int x; //element itself
};

//Struct Sparse Matrix
struct sparse{
    int m,n; //dimensions
    int num;
    struct ele *p;
};

void display(sparse *s){
    cout<<"Matrix: "<<endl;
    int num=0;
    for(int i=0;i<s->m;i++){
        for(int j=0;j<s->n;j++){
            if(s->p[num].i==i && s->p[num].j==j){
                cout<<s->p[num++].x<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void create(sparse *s){
    cout<<"Enter Dimensions: ";
    cin>>s->m>>s->n;
    cout<<"Enter nums of non-Zero elements: ";
    cin>>s->num;
    s->p = (ele *)malloc(sizeof(ele)*s->num);
    cout<<"Enter "<<s->num<<" row, column and element: ";
    for(int i=0;i<s->num;i++)
        cin>>s->p[i].i>>s->p[i].j>>s->p[i].x;
}

int main(){
    sparse s1;
    sparse *s=&s1;
    create(s);
    display(s);
    return 0;
}