#include<iostream>
#include<string.h>
using namespace std;

char* reversed(char s[]){
    int len = strlen(s);
    char temp;
    for(int i=0,j=len-1;i<=j;i++,j--){
        temp = s[j];
        s[j] =  s[i];
        s[i] = temp;
    }
    return s;
}

int main(){
    char s[] = "reverse";
    cout<<reversed(s);
}