#include<iostream>
using namespace std;

void permuatations(char s[], int len, int k){
    static int *flag_array = new int[len];
    static int set = 0;
    if(!set){
        for(int i=0;i<len;i++)
            flag_array[i]=0;
        set=1;
    }
    static char *s1 = new char[len];

    if(s[k]=='\0'){
        s1[k] = '\0';
        printf("%s\n",s1);
    }
    else{
        for(int i=0;s[i]!='\0';i++){
            if(flag_array[i]==0){
                s1[k] = s[i];
                flag_array[i] = 1;
                permuatations(s,len, k+1);
                flag_array[i]=0;
            }
        }
    }
}

int main(){
    char *s = NULL;
    size_t buffer = 100;
    cout<<"enter string: ";
    getline(&s,&buffer,stdin);
    int len=0;
    while(s[len]!='\n')
        len++;
    s[len]='\0';
    permuatations(s,len,0);
    delete []s;
}