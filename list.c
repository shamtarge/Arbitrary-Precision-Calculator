#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "list.h"

int totlen[10];
int lenBefDec[10];
int lenAftDec[10];
int l=0;
char result[100];
void initli(){
    for(int i=1; i<10;i++){
        checklist[i].len=-1;
        checklist[i].deci=0;
        checklist[i].sign=0;
    }
    for(int j=1; j<10;j++){
        totlen[j]=0;
        lenBefDec[j]=0;
        lenAftDec[j]=0;
    }
    
    for(int i = 1; i<=10; i++){
        head[i] = list[i] = NULL;
    }
}

void totalLength(int i){
    totlen[i]=0;
    node *z;
    z=head[i];
    if(head[i]==NULL){
        totlen[i]=0;
        return;
    }
    while(z->next!=NULL){
        totlen[i]++;
        z=z->next;
    }
    totlen[i]++;
}

void lenBeforeDec(int i){
    totalLength(i);
    if(checklist[i].len==-1){
        lenBefDec[i]= totlen[i];
    }
    else{
        lenBefDec[i]= totlen[i]-checklist[i].len;
    }
}


void push(char x,int i){
    node *nn;
    nn = (node*)malloc(sizeof(node));
    if(x == '.'){
        // nn ->data = '.';
        checklist[i].deci=1;
        checklist[i].len=0;
        // totlen[i]--;
        return;
    }
    else if(x>='0' && x<='9'){
        if(checklist[i].len>=0){
            checklist[i].len++;
        }
        nn ->data = x - '0';
    }
    nn ->next = NULL;
    nn ->prev = NULL;
    if (head[i] == NULL){
        list[i] = head[i] = tail[i] = nn;
    }
    else{
        tail[i] -> next = nn;
        nn -> prev = tail[i];
        tail[i] = tail[i] -> next;
    }
    // totlen[i]++;
    return;
}

void display(int i){
    if (head[i] == NULL){
        printf("List is Empty\n");
        return;
    }
    node *p = head[i];
    int flag1=1;
    lenBeforeDec(i);
    while(p->next!=NULL){

        printf("%d", p->data);
        if(checklist[i].deci==1 && flag1 == lenBefDec[i]){
            printf(".");
        }
        
        
        flag1++;
        p = p->next;
    }
    printf("%d", p->data);
    printf("\n");
    return;
}




void pushFront(char x,int i){
    node *nn;
    nn = (node*)malloc(sizeof(node));
    nn ->data = x - '0';
    nn ->prev = NULL;
    nn ->next = head[i];
    head[i] -> prev = nn;
    head[i] = head[i] -> prev;
    list[i] = head[i];
    // totlen[i]=totlen[i]+1;
    // lenBefDec[i]++;
    // printf("hello\n");
    return;
}



void equalizer(int a, int b){
    totalLength(a);
    lenBeforeDec(a);
    totalLength(b);
    lenBeforeDec(b);
    if(lenBefDec[a]<0){
        lenBefDec[a]=totlen[a];
    }
    if(lenBefDec[b]<0){
        lenBefDec[b]=totlen[b];
    }
    // no deci point in both exp
    if(totlen[a] == lenBefDec[a] && totlen[b] == lenBefDec[b]){
        if(totlen[a] == totlen[b]){
            return;
        }
        else if(totlen[a]>totlen[b]){
            // int a = totlen[a] - totlen[b];
            // printf("hek1234 : %d\n", totlen[a] - totlen[b]);
            // printf("totlen1 %d\n", totlen[1]);
            // printf("totlen2 %d\n", totlen[2]);
            // printf("lenbd1 %d\n", lenBefDec[1]);
            // printf("lenbd2 %d\n", lenBefDec[2]);
            for(int k=0; k<(totlen[a] - totlen[b]); k++){
                // printf("hek\n");
                pushFront('0',b);
                // totlen[b]++;
            }
        }
        else if(totlen[b]>totlen[a]){
            // int a = totlen[b] - totlen[a];
            for(int i=0; i<totlen[b] - totlen[a]; i++){
                pushFront('0',a);
            }
        }
        totalLength(a);
        lenBeforeDec(a);
        totalLength(b);
        lenBeforeDec(b);
        return;
    }
    // deci pt in 1st exp
    else if(totlen[a]!=lenBefDec[a] && totlen[b] == lenBefDec[b]){
        // int a = totlen[a]-lenBefDec[a];
        //putting deci and zero
        push('.',b);
        for(int i=0; i<totlen[a]-lenBefDec[a]; i++){
            push('0',b);
        }
        // matching bef deci exp
        if(lenBefDec[a] == lenBefDec[b]){
            return;
        }
        else if(lenBefDec[a]>lenBefDec[b]){
            for(int i=0; i<(lenBefDec[a]-lenBefDec[b]); i++){
                pushFront('0',b);
            }
        }
        else if(lenBefDec[b]>lenBefDec[a]){
            for(int i=0; i<(lenBefDec[b]-lenBefDec[a]); i++){
                pushFront('0',a);
            }
        }
        totalLength(a);
        lenBeforeDec(a);
        totalLength(b);
        lenBeforeDec(b);
        return;
    }

    // deci pt in 2nd exp
    else if(totlen[a]==lenBefDec[a] && totlen[b]!= lenBefDec[b]){
        // int a = totlen[b]-lenBefDec[b];
        push('.',a);
        for(int i=0; i<totlen[b]-lenBefDec[b]; i++){
            push('0',a);
        }
        // matching bef deci exp
        if(lenBefDec[a] == lenBefDec[b]){
            return;
        }
        else if(lenBefDec[a]>lenBefDec[b]){
            for(int i=0; i<(lenBefDec[a]-lenBefDec[b]); i++){
                pushFront('0',b);
            }
        }
        else if(lenBefDec[b]>lenBefDec[a]){
            for(int i=0; i<(lenBefDec[b]-lenBefDec[a]); i++){
                pushFront('0',a);
            }
        }
        totalLength(a);
        lenBeforeDec(a);
        totalLength(b);
        lenBeforeDec(b);
        return;
    }

    // both have deci
    else if(totlen[a] != lenBefDec[a] && totlen[b] != lenBefDec[b]){
        lenAftDec[a] = totlen[a] - lenBefDec[a];
        lenAftDec[b] = totlen[b] - lenBefDec[b];
        if(lenBefDec[a] == lenBefDec[b] && lenAftDec[a] == lenAftDec[b]){
            return;
        }
        // matching bef deci exp
        if(lenBefDec[a]>lenBefDec[b]){
            // printf("lenbefdecexp1 : %d\n", lenBefDec[a]-lenBefDec[b]);
            for(int i=0; i<(lenBefDec[a]-lenBefDec[b]); i++){
                pushFront('0',b);
            }
        }
        else if(lenBefDec[b]>lenBefDec[a]){
            // printf("lenbefdecexp2 : %d\n", lenBefDec[b]-lenBefDec[a]);
            for(int i=0; i<(lenBefDec[b]-lenBefDec[a]); i++){
                pushFront('0',a);
            }
        }
        // matching after deci exp
        if(lenAftDec[a]>lenAftDec[b]){
            // printf("lenaftdecexp1 : %d\n", lenAftDec[a]-lenAftDec[b]);
            for(int i=0; i<(lenAftDec[a]-lenAftDec[b]); i++){
                push('0',b);
            }
        }
        else if(lenAftDec[b]>lenAftDec[a]){
            // printf("lenaftdecexp2 : %d\n", lenAftDec[b]-lenAftDec[a]);
            for(int i=0; i<(lenAftDec[b]-lenAftDec[a]); i++){
                push('0',a);
            }
        }
        totalLength(a);
        lenBeforeDec(a);
        totalLength(b);
        lenBeforeDec(b);
        return;
    }
}


void delete(int i){
    node *g, *d;
    g=head[i];
    while(g->next!=NULL){
        d=g->next;
        free(g);
        g=d;
    }
    // printf("del1\n");
    free(g);
    // printf("del342\n");
    list[i]=head[i]=tail[i]=NULL; 
}

void add(int a, int b, char result[]){
    node *p, *q;
    p = tail[a];
    q = tail[b];
    int res, carry = 0;
    char sum[100];
    int i = 0;
    // display(a);
    // display(b);
    while (p!= NULL){
        res = p->data + q->data + carry;
        // printf("sh1\n");
        if (res>9){
            sum[i] = res%10 +'0';
            carry = res/10;
            i++;
        }
        else{
            sum[i] = res+'0';
            carry=0;
            i++;
        }
        if(p==head[a]){
            if(carry!=0){
                sum[i]=carry+'0';
                i++;
            }
            break;
        }
        p=p->prev;
        q=q->prev;
        // printf("sh2\n");
    }


    int deciafter;
    totalLength(a);
    lenBeforeDec(a);
    // printf("\ntot: %d\n", totlen[a]);
    // printf("\nlbd: %d\n", lenBefDec[a]);
    deciafter = totlen[a]-lenBefDec[a];
    // printf("\nlad: %d\n", deciafter);
    int k=0;
    for(int j=i-1; j>=0; j--){
        // printf("j: %d\n", j);
        result[k]=sum[j];
        // printf("\nk: %d\n", k);
        if(deciafter!=0 && j==deciafter){
            k++;
            result[k] = '.';
            // k++;
        }

        k++;

    }

    l=k;

    return;
}

void subtract(int a, int b, char result[]){
    node *p, *q;
    p = head[a];
    q = head[b];
    int num1=0, num2=0;
    int aaa;
    char ba[50];
    // display(a);
    // display(b);
    while(p!=NULL || q!=NULL){
        // printf("inwhile\n");
        if(list[a]){
            // printf(/"ina\n");
            num1=num1*10+p->data;
            p=p->next;
        }
        if(list[b]){
            // printf("inb\n");
            num2=num2*10+q->data;
            q=q->next;
        }
    }

    aaa=num1-num2;
    if(aaa<0){
        checklist[b-1].sign=1;
        aaa = aaa*-1;
    }
    // printf("a: %d\n", aaa);
    int h;
    int deciafter;
    totalLength(a);
    lenBeforeDec(a);
    deciafter = totlen[a]-lenBefDec[a];
    for(h = 0; aaa!=0; h++){
        // printf("infor1\n");
        ba[h]=aaa%10+'0';
        aaa=aaa/10;
        // printf("ba: %c\n", ba[h]);
    }
    // printf("for1pas\n");
    int k=0;
    for(int m=h-1; m>=0; m--){
        // printf("infor2\n");
        result[k]=ba[m];

        if(deciafter!=0 && deciafter==m){
            k++;
            result[k] = '.';
        }
        // printf("res: %c\n", result[k]);
        k++;
    }
    // printf("for21pas\n");
    l=k;   
}

void mul(int a, int b, char result[]){
    node *p, *q;
    p = head[a];
    q = head[b];
    int num1=0, num2=0;
    int aaa;
    char baa[50];
    // printf("a1: %d\n", aaa);
    // display(a);
    // display(b);
    // printf("num1: %d\n", num1);
    // printf("num2: %d\n", num2);
    // printf("befwhil\n");
    while(p!=NULL || q!=NULL){
        if(p!=NULL){
            num1=num1*10+p->data;
            p=p->next;
            // printf("1if\n");
        }
        if(q!=NULL){
            num2=num2*10+q->data;
            q=q->next;
            // printf("2if\n");
        }
    }
    // printf("num1: %d\n", num1);
    // printf("num2: %d\n", num2);
    // printf("aftfwhil\n");
    aaa=num1*num2;
    int h;
    // printf("a: %d\n", aaa);
    for(h = 0; aaa!=0; h++){
        baa[h]=aaa%10+'0';
        aaa=aaa/10;
        // printf("ba: %c\n", baa[h]);
        // printf("in for 1\n");
    }
    int k=0;
    int deciafter1,deciafter2;
    totalLength(a);
    lenBeforeDec(a);
    totalLength(b);
    lenBeforeDec(b);
    deciafter1 = totlen[a]-lenBefDec[a];
    deciafter2 = totlen[b]-lenBefDec[b];
    for(int m=h-1; m>=0; m--){
        result[k]=baa[m];
        if(deciafter1!=0 || deciafter2!=0){
            // First has decimal
            if(deciafter1!=0 && deciafter2==0 && deciafter1==m){
                k++;
                result[k] = '.';
            }
            // Second has decimal point
            else if(deciafter1==0 && deciafter2!=0 && deciafter2==m){
                k++;
                result[k] = '.';
            }
            // Both have decimal point
            else if(deciafter1!=0 && deciafter2!=0 && deciafter1+deciafter2==m){
                k++;
                result[k] = '.';
            }
        }
        k++;
        // printf("in for 2\n");
    }
    // printf("end\n");
    l=k;
}

void divi(int a, int b, char result[]){
    node *p, *q;
    p = head[a];
    q = head[b];
    float num1=0, num2=0;
    float aaa=0;
    char ba[50];
    int deciafter1,deciafter2;
    totalLength(a);
    lenBeforeDec(a);
    totalLength(b);
    lenBeforeDec(b);
    deciafter1 = totlen[a]-lenBefDec[a];
    deciafter2 = totlen[b]-lenBefDec[b];
    while(p!=NULL || q!=NULL){
        if(p!=NULL){
            num1=num1*10+p->data;
            p=p->next;
            // printf("1if\n");
        }
        if(q!=NULL){
            num2=num2*10+q->data;
            q=q->next;
            // printf("2if\n");
        }
    }
    for(int ra=0; ra<deciafter1; ra++){
        num1 = num1*0.1;
    }
    for(int ra=0; ra<deciafter2; ra++){
        num2 = num2*0.1;
    }
    if(num2==0){
        printf("\n**To Infinity and Beyond**\n");
        return;
    }
    // printf("num1: %f\n", num1);
    // printf("num2: %f\n", num2);
    aaa=num1/num2;
    // printf("a1: %f\n", aaa);
    int aa1;
    aa1 = (int)aaa;
    // printf("a2: %d\n", aa1);
    int h;
    if(aa1==0){
        result[0]='0';
        l=1;
        return;
    }
    for(h = 0; aa1!=0; h++){
        ba[h]=aa1%10+'0';
        // printf("a3: %d\n", aaa);
        aa1=aa1/10;
        // printf("ba: %c\n", ba[h]);
        // printf("in for 1\n");
    }
    int k;
   
    for(int m=h-1; m>=0; m--){
        result[k]=ba[m];
        // if(deciafter!=0 && deciafter==m){
        //     k++;
        //     result[k] = '.';
        // }
        k++;
        // printf("in for 2\n");
    }
    l=k;
    return;
}

void mod(int a, int b, char result[]){
    node *p, *q;
    p = head[a];
    q = head[b];
    int num1=0, num2=0;
    int aaa;
    char ba[50];
    while(p!=NULL || q!=NULL){
        if(p!=NULL){
            num1=num1*10+p->data;
            p=p->next;
            // printf("1if\n");
        }
        if(q!=NULL){
            num2=num2*10+q->data;
            q=q->next;
            // printf("2if\n");
        }
    }
    aaa=num1%num2;
    int h;
    if(aaa==0){
        result[0]='0';
        l=1;
        return;
    }
    for(h = 0; aaa!=0; h++){
        ba[h]=aaa%10+'0';
        aaa=aaa/10;
    }
    int k;
    int deciafter;
    totalLength(a);
    lenBeforeDec(a);
    for(int m=h-1; m>=0; m--){
        result[k]=ba[m];
        if(deciafter!=0 && deciafter==m){
            k++;
            result[k] = '.';
        }
        k++;
    }
    l=k;
}
// int power(int s, int p){
//     int t=s;
//     for(int i=0; i<p-1; i++){
//         s=s*t;
//     }
//     return(s);
// }
void expo(int a, int b, char result[]){

    node *p, *q;
    p = head[a];
    q = head[b];
    float num1=0, num2=0;
    float aaa=0;
    char ba[50];
    int deciafter1,deciafter2;
    totalLength(a);
    lenBeforeDec(a);
    totalLength(b);
    lenBeforeDec(b);
    deciafter1 = totlen[a]-lenBefDec[a];
    deciafter2 = totlen[b]-lenBefDec[b];
    while(p!=NULL || q!=NULL){
        if(p!=NULL){
            num1=num1*10+p->data;
            p=p->next;
            // printf("1if\n");
        }
        if(q!=NULL){
            num2=num2*10+q->data;
            q=q->next;
            // printf("2if\n");
        }
    }
    // if(deciafter1==0 && deciafter2==0){
    //     num1=num1+0.1;
    //     num2=num2+0.1;
    // }
    for(int ra=0; ra<deciafter1; ra++){
        num1 = num1*0.1;
    }
    for(int ra=0; ra<deciafter2; ra++){
        num2 = num2*0.1;
    }
    // printf("num1: %f\n", num1);
    // printf("num2: %f\n", num2);
    aaa=pow(num1,num2);
    
    int aa1;
    aa1 = (int)aaa;
    // printf("a2: %d\n", aa1);
    // int h;6725.3456^2
    if(aa1==0){
        result[0]='0';
        l=1;
        return;
    }
    int h;
  
    for(h = 0; aa1!=0; h++){
        ba[h]=aa1%10+'0';
        aa1=aa1/10;
    }
    int k;
    int deciafter;
    totalLength(a);
    lenBeforeDec(a);
    for(int m=h-1; m>=0; m--){
        result[k]=ba[m];
        if(deciafter!=0 && deciafter==m){
            k++;
            result[k] = '.';
        }
        k++;
    }
    l=k;
}