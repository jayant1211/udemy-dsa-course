#include<iostream>
#include<cstring>

using namespace std;

int countWords(char *s){
    //need to count whitespaces
    int count=0;
    for(unsigned int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            count++;
        }
    }
    return count+1;
}

int countVowels(char s[]){
    int count = 0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='A' || s[i]=='I' || s[i]=='E' || s[i]=='O' || s[i]=='U' || 
        s[i]=='a' || s[i]=='i' || s[i]=='e' || s[i]=='o' || s[i]=='u'){
            count++;
        }
    }
    return count;
}

int main(){
    char sentence[] = "hello this is sample containing seven words";
    char s[] = "abcdieruhieols";
    cout<<"words: "<<countWords(sentence);
    cout<<"\nVowels: "<<countVowels(s);
}