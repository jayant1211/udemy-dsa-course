#include<iostream>
using namespace std;

int main(){
    // a character
    char a  = 'a'; //always to be declared with single quotes;
    //char b = "a"; //error

    //string - array for characters
    char c[] = {'a','b','c','d'};

    //how do we end a string:
    //\0 is a null character - which denotes end of a string 
    char name[] = {'j','a','y','a','n','t','\0'};
    for(int i=0;name[i]!='\0';i++){
        cout<<name[i];
    }
    cout<<"\n";

    //double quote declaration denotes a string:
    char full_name[] = "jayant meshram";
    //this will automatically append null character at end
    for(int i=0;full_name[i]!='\0';i++){
        cout<<full_name[i];
    }

    //cin will read input only till whitespace - end of word, not of string, as in - 
    char str1[100];
    cout<<"\nenter name: ";
    cin>>str1; // typed -  jayant meshram
    cin.ignore();
    cout<<str1; // will print only jayant

    //instead of cin, getline(in cpp) and fgets(in c) is more ideal
    //getline - handles string objects
    string str2;
    cout<<"\nenter name:";
    getline(cin,str2);
    cout<<str2;

    //fgets - c function
    char str3[100];
    cout<<"\nenter name: ";
    fgets(str3,100,stdin);
    printf("%s ",str3);
}