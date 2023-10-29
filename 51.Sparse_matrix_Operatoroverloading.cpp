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
        friend istream& operator >>(istream &is,sparse &s);
        friend ostream& operator <<(ostream &os,sparse &s);
        ~sparse(){
            delete []p;
        }
        sparse operator+(sparse &s2);
};

istream& operator >>(istream &is,sparse &s){
    cout<<"enter number of elements: ";
    cin>>s.nums;
    s.p = new element[s.nums];
    cout<<"enter "<<s.nums<<" row, column and eleement: ";
    for(int i=0;i<s.nums;i++)
        cin>>s.p[i].i>>s.p[i].j>>s.p[i].x;
    return is;
}

ostream& operator <<(ostream &os,sparse &s){
    int num=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(s.p[num].i == i && s.p[num].j == j){
                cout<<s.p[num++].x<<" ";
            } else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return os;
}

sparse sparse::operator+(sparse &s2){
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

int main(){
    sparse s1(3,3);
    cin>>s1;
    sparse s2(3,3);
    cin>>s2;
    cout<<"\n";
    cout<<s1;
    cout<<" + \n";
    cout<<s2;
    cout<<" = \n";
    sparse s3 = s1+s2;
    cout<<s3;
}