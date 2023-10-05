#include<iostream>
using namespace std;

bool isPalindrome(char *s){
    int len=0;
    //or use strlen 
    while(s[len]!='\0')
        len++;
    len--;

    for(int i=0,j=len-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    char *s=NULL;
    cout<<"Enter string: ";
    size_t buffer = 100;
    getline(&s,&buffer,stdin);
    cout<<"is palindrome: "<<isPalindrome(s);
}