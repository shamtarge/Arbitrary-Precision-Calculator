#include<stdio.h>
#include<stdlib.h>
#include "list.c"

#define MAX1 50
#define MAX2 50

int main(){
    initli();
    // Storing the elements in list
    char array1[MAX1];
    char array2[MAX2];
    printf("Enter the Expression 1: ");
    gets(array1);
    printf("Enter the Expression 2: ");
    gets(array2);
    for(int i=0;array1[i]!='\0';i++){
        push(array1[i],1);
    }
    for(int i=0;array2[i]!='\0';i++){
        push(array2[i],2);
    }
    //
    totalLength(1);
    lenBeforeDec(1);
    totalLength(2);
    lenBeforeDec(2);

    printf("The 1st Entered Expression is: ");
    display(1);
    printf("The 2nd Entered Expression is: ");
    display(2);
    // lenBefDec1 = 5;
    // lenBefDec2 = 2;
    printf("totlen1 %d\n", totlen[1]);
    printf("totlen2 %d\n", totlen[2]);
    printf("lenbd1 %d\n", lenBefDec[1]);
    printf("lenbd2 %d\n", lenBefDec[2]);
    // lenBefDec1 = totlen1;
    // lenBefDec2 = totlen2;
    equalizer(1,2);

    printf("The 1st Entered Expression is: ");
    display(1);
    printf("The 2nd Entered Expression is: ");
    display(2);

    // add(1,2);
    // subtract(1,2);
    return 0;
}
