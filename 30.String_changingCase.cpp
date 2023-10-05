#include<iostream>
using namespace std;

void changeCase(char s[]){
    //A - 65
    //a - 97
    printf("\nString earlier: %s",s);
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<97){
            //uppper case - 
            s[i]+=32;
        } else if(s[i]>=97 && s[i]<123){
            // lower case - 
            s[i]-=32;
        }
    }
    cout<<"i is: "<<i<<endl;
    printf("String now is: %s",s);
}

int main(){
    char s[100];
    cout<<"enter string: ";
    fgets(s,100,stdin);
    changeCase(s);
}