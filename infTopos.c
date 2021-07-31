#include "infTopos.h"
#include<limits.h>
#include<stdlib.h>
#include <stdio.h>
#include<ctype.h>
void init(stack *s, int len){
    s->a = (char*)malloc(sizeof(char)*len);
    s->size = len;
    s->top = -1;
}
int isFull(stack s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}
void push1(stack *s, char d){
    if(isFull(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}
void display1(stack *s){
    if(isEmpty(*s))
        return ;
    else {
        s->top++;
        printf("%d", s->a[s->top]);
        return;
    }
}
char pop(stack *s){
    char e = '#';
    if(!isEmpty(*s)){
        e = s->a[s->top];
        s->top--;
    }
    return e;

}

char peek(stack s){
    return s.a[s.top];
}

int precedence(char c){
    if(c == '+')
        return 10;
    else if(c == '-')
        return 10;
    else if(c == '*')
        return 20;
    else if(c == '/')
        return 20;
    else if(c == '%')
        return 20;
    else if(c == '^')
        return 30;
    else if(c == '(')
        return 5;
    return 0;
}

void infcon(char E[], char postfix[], stack s){
    static int j = 0;
    char c;
    static int i=0;
    while(E[i]!= '\0'){
        c = E[i];
        if(isdigit(c)){
            postfix[j++] = c ;
            if(!isdigit(E[i+1]) && E[i+1]!='.')
                postfix[j++] = ' ';
        }
        else if( c == '(')
            push1(&s,'(');
        else if(c == ')'){
            while(!isEmpty(s) && peek(s)!= '('){
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            if(peek(s) == '(')
                pop(&s);
        }
        else if(c=='.'){
            postfix[j++] = '.';
        }
        else if(c==' '||c=='\0'){
            break;
        }
        else {
            if( c == '+' || c =='-' || c == '*'|| c == '/' || c == '%'||c == '^') {
                if(isEmpty(s))
                    push1(&s, c);
                else {
                    while(!isEmpty(s) && precedence(peek(s)) >= precedence(c)){
                        postfix[j++] = pop(&s);
                        postfix[j++] = ' ';
                    }
                    push1(&s, c);
                }
            }
        }
        i++;
    }

    while(!isEmpty(s)){
        // display1(&s);
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
}