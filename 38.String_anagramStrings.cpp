#include<iostream>
using namespace std;

bool anagram(char *s1,char *s2){
    int len1=0;
    int len2=0;
    while(s1[len1]!='\n')
        len1++;

    while(s2[len2]!='\n')
        len2++;
    cout<<"\nlen"<<len1;
    if(len1!=len2)
        return false;
    else{
        //checking anagram using hash table
        //assuming all are lowercase 
        int *hash_table = new int[26];
        //traverse from string 1
        for(int i=0;i<len1;i++){
            hash_table[s1[i]-'a']+=1; 
            hash_table[s2[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(hash_table[i]!=0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    char *s1 = NULL;
    char *s2 = NULL;
    size_t buffer=100;
    cout<<"Enter string 1: ";
    getline(&s1,&buffer,stdin);
    cout<<"Enter string 2: ";
    getline(&s2,&buffer,stdin);
    cout<<s1<<" and "<<s2<<" are anagrams: "<<anagram(s1,s2);
    free(s1);
    free(s2);
}