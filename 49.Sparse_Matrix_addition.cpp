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

sparse* addition(sparse *s1, sparse *s2){
    int i,j,k;
    i=j=k=0;
    sparse *sum;
    sum = (sparse *)malloc(sizeof(sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->p = (ele *)malloc(sizeof(ele)*(s1->num + s2->num));
    if(!(s1->m == s2->m && s1->n == s2->n)){
        cout<<"Dimensions are different. Sum cannot be calculated.\n";
        return sum;
    }
    else{
        //sum can be calculated
        while(i<s1->num && j<s2->num){
            if(s1->p[i].i<s2->p[j].i){
                sum->p[k++] = s1->p[i++];
            } else if(s1->p[i].i>s2->p[j].i){
                sum->p[k++] = s2->p[j++];
            } else{
                if(s1->p[i].j<s2->p[j].j){
                    sum->p[k++] = s1->p[i++];
                } else if(s1->p[i].j>s2->p[j].j){
                    sum->p[k++] = s2->p[j++];
                } else{
                    sum->p[k] = s1->p[i++];
                    sum->p[k++].x += s2->p[j++].x;
                }
            }
        }
        while(i<s1->num)
            sum->p[k++] = s1->p[i++];
        while(j<s2->num)
             sum->p[k++] = s2->p[j++];
            
        sum->num = k;
        return sum;
    }
}

int main(){
    sparse *s1,*s2;
    s1=(sparse *)malloc(sizeof(sparse));
    s2=(sparse *)malloc(sizeof(sparse));
    cout<<"First Matrix: \n";
    create(s1);
    cout<<"Second Matrix: \n";
    create(s2);
    cout<<"ADDITION: "<<endl;
    display(s1);
    cout<<" + \n";
    display(s2);
    cout<<" = \n";
    sparse* result = addition(s1,s2);
    display(result);
}