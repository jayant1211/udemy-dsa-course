#include<iostream>
using namespace std;

void compare(char *s1,char *s2){
    int i;
    for(i=0;(s1[i]!='\0' && s2[i]!='\0');i++){
        if(s1[i]>s2[i]){
            cout<<s2<<" comes before "<<s1<<endl;
            return;
        } else if(s1[i]<s2[i]){
            cout<<s1<<" comes before "<<s2<<endl;
            return;
        } 
    }
    if(s2[i]=='\0' && s1[i]!='\0'){
        cout<<s2<<" comes before "<<s1<<endl;
    } else if(s2[i]!='\0' && s1[i]=='\0'){
        cout<<s1<<" comes before "<<s2<<endl;
    } else{
        cout<<"both are same";
    }
}

int main(){
    char *s1=NULL;
    char *s2=NULL;
    size_t bufferSize = 100;
    cout<<"enter s1: ";
    getline(&s1,&bufferSize,stdin);
    cout<<"enetr s2: ";
    getline(&s2,&bufferSize,stdin);
    compare(s1,s2);

}