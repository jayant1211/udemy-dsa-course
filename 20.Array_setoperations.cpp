/***
 * union - unsorted, sorted 
 * intersection - unsorted, sorted 
 * A - B - unsorted, sorted
 * set meembership - done as includes
*/
#include<iostream>
using namespace std;

class arr{
    private:
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
            A = new int[5];
            cout<<"Enter "<<length<<" elements: ";
            for(int i=0;i<length;i++)
                cin>>A[i];
        }
        void display(){
            for(int i=0;i<length;i++)
                cout<<A[i]<<" ";
            cout<<endl;
        }
        void set_val(int i,int j){
            size = i;
            length = j;
            A = new int[size];
        }
        int get_size(){
            return size;
        }
        int get_len(){
            return length;
        }
        int* get_pointer(){
            return A;
        }
        bool includes(int n){
            for(int i=0;i<length;i++){
                if(n==A[i]){
                    return true;
                }
            }
            return false;
        }
        ~arr(){
            delete[] A;
        }
};

arr uni(arr &a,arr &b, int isSorted){
    arr result;
    result.set_val(a.get_size()+b.get_size(), a.get_len() + b.get_len());
    
    // not sorted
    if(not isSorted){
        int i=0;
        for(;i<a.get_len();i++){
            result.get_pointer()[i] = a.get_pointer()[i];
        }
        for(int j=0;j<b.get_len();j++){
            if(not result.includes(b.get_pointer()[j]))
                result.get_pointer()[i++] = b.get_pointer()[j];
        }
        return result;
    }
    //sorted array
    else{
        int i,j,k;
        i=j=k=0;
        for(;i<a.get_len() and j<b.get_len();){
            if(a.get_pointer()[i]<b.get_pointer()[j]){
                result.get_pointer()[k++] = a.get_pointer()[i++];
            } else if(a.get_pointer()[i]>b.get_pointer()[j]){
                result.get_pointer()[k++] = b.get_pointer()[j++];
            } else{
                result.get_pointer()[k++] = a.get_pointer()[i++];
                j++;
            }
        }
        for(;i<a.get_len();i++){
            result.get_pointer()[k++] = a.get_pointer()[i];
        }
        for(;j<b.get_len();j++){
            result.get_pointer()[k++] = a.get_pointer()[j];
        }
        return result;
    }
}

arr intersection(arr &a, arr&b, int isSorted){
    arr result;
    int len = min(a.get_len(),b.get_len());
    int size = min(a.get_size(),b.get_size());
    result.set_val(size,len);
    
    if(not isSorted){
        //unsorted
        int j=0;
        for(int i=0;i<a.get_len();i++){
            if(b.includes(a.get_pointer()[i])){
                result.get_pointer()[j++] = a.get_pointer()[i];
            }
        }
        return result;
    } else{
        //sorted
        int i,j,k;
        i=j=k=0;
        for(;i<a.get_len() and j<b.get_len();){
            if(a.get_pointer()[i]>b.get_pointer()[j]){
                j++;
            } else if(a.get_pointer()[i]<b.get_pointer()[j]){
                i++;
            } else{
                result.get_pointer()[k++] = a.get_pointer()[i++];
                j++;
            }
        }
        return result;
    }
}

arr AminusB(arr &a, arr &b, int sorted){
    //should perform a-b
    arr result;
    result.set_val(a.get_size(),a.get_len());

    if(not sorted){
        int k=0;
        //unsorted
        for(int i=0;i<a.get_len();i++){
            if(not b.includes(a.get_pointer()[i])){
                result.get_pointer()[k++] = a.get_pointer()[i];
            }
        }
        return result;
    } else{
        int i,j,k;
        i=j=k=0;

        for(;i<a.get_len() and j<b.get_len();){
            if(a.get_pointer()[i]<b.get_pointer()[j]){
                result.get_pointer()[k++] = a.get_pointer()[i++];
            } else if(a.get_pointer()[i]>b.get_pointer()[j]){
                j++;
            } else{
                i++;
                j++;
            }
        }
        for(;i<a.get_len();i++){
            result.get_pointer()[k++] = a.get_pointer()[i];
        }
        return result;
    }
}

int main(){
    arr A(10,5),B(6,3);
    arr C = uni(A,B,1);
    C.display();
    arr D = intersection(A,B,1);
    D.display();
    arr E = AminusB(A,B,1);
    E.display();
}