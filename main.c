/*
111903026
Sham Balasaheb Targe
Division 1 Batch S2
*/
#include "infTopos.c"
#include "tp.c"
#include <stdio.h>
// #include <ctype.h>
// #define size 100
int main(){
    char E[50];
    printf("\nEnter the infix Expression: ");
    gets(E);
    stack s;
    init(&s, 50);
    char postfix[70];

    infcon(E, postfix, s);
 
    printf("\nPostfix Expression is : ");
    for (int i = 0; postfix[i] != '\0'; i++){
        printf("%c", postfix[i]);
    }

    printf("\n");
    initli();
    tp(postfix);
  
    totalLength(number);
  
    for (int c = 1; c < number; c++){
        printf("\n**OUTPUT** \n");
        if (checklist[c].sign == 1){
            printf("-");
        }
        display(c);
    }

    int val;
    do{
        printf("\nPerform Trignometric Operation??\n1 :YES \n2 : NO\n");
        scanf("%d", &val);
        if(val==2){
            break;
        }
        double angle;
        int func;
        printf("1: Sine\n2: Cosine\n3: Tangent\n4: Cotangent\n5: Secant\n6: Cosecant\n7: Sinh\n8: Cosh\n9: Tanh\n10: All Above Trignometric Functions\n11: Square Root\n");
        scanf("%d", &func);
        if(func>=1&&func<=10){
            printf("Enter Angle in Degrees : ");
            scanf("%lf", &angle);
            trignometry(angle,func);
        }
        else{
            printf("Enter Value to find sqrt: ");
            scanf("%lf", &angle);
            trignometry(angle,func);
        }
    }while(val!=2);

    int his;
    printf("\nWant to View History ??\n1 :YES \n2 : NO\n");
    scanf("%d", &his);
    if(his==1){
        for(int h=0; history[h] != '\0'; h++){
            printf("%c", history[h]);
        }
    }

    return 0;
}


/*
237.436+3637.84*3.04-3258.7/468.06+237.56897+6725.3456^2.24+21567463%38 = 375054216.03857 + 31
73.05439-654732.9 = -10414.75121
21567463%38 = 31
6725.3456^2 = 45230268
34739*34567 = 1200823013
2359876932.86/346.37 = 6813167
278548293598+8235268768265.32523 = 8513817061863.32523

*/