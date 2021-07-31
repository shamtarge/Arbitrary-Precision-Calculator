typedef struct stack{
    char *a;
    int size;
    int top;
}stack;

void init(stack *s, int len);
void push1(stack *s, char d);
int isFull(stack s) ;
int isEmpty(stack s);
char pop(stack *s);
char peek(stack s);