#include<stdio.h>

struct rectangle{
    char c;
    int l;
    int b;
    
};

int main(){
    struct rectangle r1={10,1};
    printf("%d",sizeof(r1));
}