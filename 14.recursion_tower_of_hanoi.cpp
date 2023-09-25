/**
 * Write problem for smaller disk (1,2 and 3) and generalise
 * 
 * if 1 disk - T(1,A,B,C): move disk from tower A to Tower C using B.
 * if 2 disks - T(2,A,B,C): i. move disk from A to B using C {T(1,A,C,B)}
 *                          ii. move disk from A to C using B //largest disk is at C
 *                          iii. move disk from B to C using A {T(1,B,A,C)}
 * if 3 disks - T(3,A,B,C): i. move 2 disks from A to B {T(2,A,C,B): we know how to do this}
 *                          ii. move disk from A to C using B //largest disk
 *                          iii. move those two disks from B to C using A {T(2,B,A,C): we know this too}
 * 
 * 
 * generalising:
 * T(n,A,B,C)-
 * 1. T(n-1,A,C,B)
 * 2. Move Disk From A to C
 * 3. T(n-1,B,A,C)
 * **/

#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C){
    if(n>=1){
        TOH(n-1,A,C,B);
        printf("Move disk from tower %d to tower %d using tower %d.\n",A,C,B);
        TOH(n-1,B,A,C);
    }
}

int main(){
    int n;
    cout<<"Number of disks: ";
    cin>>n;
    cout<<"SOLUTION:\n";
    TOH(n,1,2,3);
}