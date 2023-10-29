#include<iostream>
using namespace std;

struct element{
    int i,j,x;
};

class sparse{
    private:
        int m,n,nums;
        element *p;
    public:
        sparse(int m, int n){
            this->m=m;
            this->n=n;
        }
        void create();
        void display();
        ~sparse(){
            delete []p;
        }
        sparse addition(sparse &s2);
};

sparse sparse::addition(sparse &s2){
    int i,j,k;
    i=j=k=0;
    sparse sum(m,n);
    sum.p = new element[nums + s2.nums];
    if(!(m == s2.m && n == s2.n)){
        cout<<"Dimensions are different. Sum cannot be calculated.\n";
        return sum;
    }
    else{
        //sum can be calculated
        while(i<nums && j<s2.nums){
            if(p[i].i<s2.p[j].i){
                sum.p[k++] = p[i++];
            } else if(p[i].i>s2.p[j].i){
                sum.p[k++] = s2.p[j++];
            } else{
                if(p[i].j<s2.p[j].j){
                    sum.p[k++] = p[i++];
                } else if(p[i].j>s2.p[j].j){
                    sum.p[k++] = s2.p[j++];
                } else{
                    sum.p[k] = p[i++];
                    sum.p[k++].x += s2.p[j++].x;
                }
            }
        }
        while(i<nums)
            sum.p[k++] = p[i++];
        while(j<s2.nums)
             sum.p[k++] = s2.p[j++];
            
        sum.nums = k;
        return sum;
    }
}

void sparse::create(){
    cout<<"enter number of elements: ";
    cin>>nums;
    p = new element[nums];
    cout<<"enter "<<nums<<" row, column and eleement: ";
    for(int i=0;i<nums;i++)
        cin>>p[i].i>>p[i].j>>p[i].x;
}

void sparse::display(){
    int num=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(p[num].i == i && p[num].j == j){
                cout<<p[num++].x<<" ";
            } else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    sparse s1(3,3),s2(3,3);
    s1.create();
    s2.create();
    s1.display();
    cout<<" + "<<endl;
    s2.display();
    sparse s3 = s1.addition(s2);
    cout<<" = "<<endl;
    s3.display();
}