#include<stdio.h>
#include<stdlib.h>
#include "list.c"
#include<math.h>
// #include "tp.h"
#define MAX1 100
#define MAX2 50
#define pi 3.141592
int l;
char result[100];
char history[100];
int number;


// void reinit(int i){
//     list[i]=head[i]=tail[i]=NULL; 
//     checklist[i].len=-1;
//     checklist[i].deci=0;
//     checklist[i].sign=0;  
//     totlen[i]=0;
//     lenBefDec[i]=0;
//     lenAftDec[i]=0; 
// }

void arrayinit(char array[], int i){
    for (int j=0; j<i; j++){
        array[j]='0';
    }
    l=0;
}

void tp(char array1[]){
    int i = 0;
    // char op;
    number=1;
    while(array1[i]!='\0'){   
        // printf("hel\n");
        if(array1[i]>='0' && array1[i]<='9'){
            // printf("i : %d\n", i);
            for(int p=i;(array1[p]!='\0' && array1[p]!=' '); p++){

                push(array1[p],number);
                // printf("pu2\n");
                i++;
            }
            number++;
            // printf("currNum : %d", number);
        }
        if(array1[i]==' '){
            i++;
        }

        else{
            char opt = array1[i];
            static int count=0;
            // int ss;
            switch (opt){
                case '+':

                    equalizer(number-2,number-1);

                    add(number-2,number-1, result);

                    delete(number-2);

                    delete(number-1);

                    number=number-2;
                    // printf("l : %d\n", l);
                    for(int p=0; p<l ; p++){
                        
                        history[count++]=result[p];
                        // count++;
                        push(result[p],number);
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    // printf("looppas\n");
                    number++;
                    arrayinit(result,l);
                    
                    break;
                case '-':
                    // i++;
                    equalizer(number-2,number-1);
                    
                    subtract(number-2 , number-1 , result);
                    // history(result);
                    delete(number-2);
                    delete(number-1);
                    number=number-2;
                    // display(number);
                    for(int p=0; p<l ; p++){
                        // printf("res[p]: %c\n", result[p]);
                        history[count++]=result[p];
                        push(result[p],number);
                        // printf("pu2\n");
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    number++;
                    arrayinit(result,l);
                    
                    break;
                case '*':
                    // equalizer(number-2,number-1);
                    mul(number-2 , number-1 , result);
                    // history(result);
                    delete(number-2);
                    delete(number-1);
                    number=number-2;
                    for(int p=0; p<l ; p++){
                        // printf("res[p]: %c", result[p]);
                        history[count++]=result[p];
                        // count++;
                        push(result[p],number);
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    
                    number++;
                    arrayinit(result,l);
                      
                    break;

                case '/':
                    divi(number-2 , number-1 , result);
                    
                    delete(number-2);
                    delete(number-1);
                    number=number-2;
                    for(int p=0; p<l ; p++){
                        // printf("res[p]: %c\n", result[p]);
                        history[count++]=result[p];
                        // count++;
                        push(result[p],number);
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    
                    number++;
                    arrayinit(result,l);
                    
                    break;
                case '%':
                    mod(number-2 , number-1 , result);
                    // history(result);
                    delete(number-2);
                    delete(number-1);
                    number=number-2;
                    for(int p=0; p<l ; p++){
                        // printf("res[p]: %c\n", result[p]);
                        history[count++]=result[p];
                        // count++;
                        push(result[p],number);
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    number++;
                    arrayinit(result,l);
                    
                    break;
                case '^':
                    // equalizer(number-2,number-1);
                    
                    expo(number-2 , number-1 , result);
                    
                    delete(number-2);
                    delete(number-1);
                    number=number-2;
                    for(int p=0; p<l ; p++){
                        
                        history[count++]=result[p];
                        // count++;
                        push(result[p],number);
                        // i++;
                    }
                    history[count++]=' ';
                    history[count++]=',';
                    history[count++]=' ';
                    number++;
                    arrayinit(result,l);
                    
                    break;
                default:
                    printf("\nInvalid ope\n");
                    break;
            }
            
            i++;
        }
        
    }
    return;
    
}




void trignometry(double x, int fun){
    double rad;
    // rad = pi/180.0;
    switch (fun){
        case 1:
            rad = pi/180.0;
            double si;
            si = sin(x*rad);
            printf("The value of sin(%.2lf) is %.2lf degrees\n", x, si);
            break;
    
        case 2:
            rad = pi/180.0;
            double co;
            co = cos(x*rad);
            printf("The value of cos(%.2lf) is %.2lf degrees\n", x, co);
            break;
    
        case 3:
            rad = pi/180.0;
            double ta;
            ta = tan(x*rad);
            printf("The value of tan(%.2lf) is %.2lf degrees\n", x, ta);
            break;
    
        case 4:
            rad = pi/180.0;
            double ct;
            ct = 1 / tan(x*rad);
            printf("The value of cot(%.2lf) is %.2lf degrees\n", x, ct);
            break;
    
        case 5:
            rad = pi/180.0;
            double se;
            se = 1 / cos(x*rad);
            printf("The value of sec(%.2lf) is %.2lf degrees\n", x, se);
            break;
        case 6:
            rad = pi/180.0;
            double cse;
            cse = 1 / sin(x*rad);
            printf("The value of cosec(%.2lf) is %.2lf degrees\n", x, cse);
            break;
        case 7:
            rad = pi/180.0;
            double sih;
            sih = sinh(x*rad);
            printf("The value of sinh(%.2lf) is %.2lf degrees\n", x, sih);
            break;
        case 8:
            rad = pi/180.0;
            double coh;
            coh = cosh(x*rad);
            printf("The value of cosh(%.2lf) is %.2lf degrees\n", x, coh);
            break;
        case 9:
            rad = pi/180.0;
            double tah;
            tah = tanh(x*rad);
            printf("The value of tanh(%.2lf)is %.2lf degrees\n", x, tah);
            break;
        case 10:
            rad = pi/180.0;
            double si1;
            si1 = sin(x*rad);
            printf("The value of sin(%.2lf) is %.2lf degrees\n", x, si1);
            double co1;
            co1 = cos(x*rad);
            printf("The value of cos(%.2lf) is %.2lf degrees\n", x, co1);
            double ta1;
            ta1 = tan(x*rad);
            printf("The value of tan(%.2lf) is %.2lf degrees\n", x, ta1);
            double ct1;
            ct1 = 1 / tan(x*rad);
            printf("The value of cot(%.2lf) is %.2lf degrees\n", x, ct1);
            double se1;
            se1 = 1 / cos(x*rad);
            printf("The value of sec(%.2lf) is %.2lf degrees\n", x, se1);
            double cse1;
            cse1 = 1 / sin(x*rad);
            printf("The value of cosec(%.2lf) is %.2lf degrees\n", x, cse1);
            double sih1;
            sih1 = sinh(x*rad);
            printf("The value of sinh(%.2lf) is %.2lf degrees\n", x, sih1);
            double coh1;
            coh1 = cosh(x*rad);
            printf("The value of cosh(%.2lf) is %.2lf degrees\n", x, coh1);
            double tah1;
            tah1 = tanh(x*rad);
            printf("The value of tanh(%.2lf) is %.2lf degrees\n", x, tah1);
            break;
        case 11:
            printf("The Square root of %lf is %.2lf \n", x, sqrt(x));
            break;
        default:
            break;
    }
    return;
}

