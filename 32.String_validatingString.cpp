#include<iostream>
#include<string.h>
using namespace std;
//only numbers[48-59] and letters[65-90, 97-122] are allowed, special characters are not

bool isString(const char s[]){
    for(int i=0;i<strlen(s);i++){
        if(!(s[i]>='0' && s[i]<='9') && !(s[i]>='A' && s[i]<='Z' ) && !(s[i]>='a' && s[i]<='z')){
            return false;
        }
    }
    return true;
}

int main(){
    char s1[] = "Jayant123";
    char s2[] = "Jayant?11";

    cout<<s1<<" : "<<isString(s1)<<endl;
    cout<<s2<<" : "<<isString(s2);
}