#include<iostream>
#include<string.h>
using namespace std;

void duplicates_v1(char s[]){
    //O(n^2)
    int len = strlen(s);
    for(int i=0;i<len-1;i++){
        if(s[i]!='-'){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    cout<<s[i]<<" is duplicated at index "<<j<<endl;
                    s[j] = '-';
                }
            }
        }
        
    }
}

void duplicates_v2(char s[]){
    //O(n)
    //assuming all are lower 
    int len = strlen(s);
    int *hash_table = new int[26];
    for(int i=0;i<len;i++){
        hash_table[s[i]-'a']+=1;
    }
    for(int i=0;i<len;i++){
        cout<<s[i]<<" is duplicated "<<hash_table[s[i]-'a']<<" times"<<endl;
    }
}

void duplicates_v3(char s[]){
    //O(n)
    //space complexity : O(1)
    long int h=0,x;

    for(int i=0;s[i]!='\0';i++){
        x=1;
        x=x<<(s[i]-'a');
        if((x&h)>0){
            //duplicate
            printf("\n%c is duplicated",s[i]);
        } else{
            //set that bit on
            h=(h|x);
        }
    }
}

int main(){
    char s[] = "aabbbaaacderfaa";
    //duplicates_v2(s);
    //duplicates_v1(s);
    duplicates_v3(s);
}