typedef struct m{
    int data;
    struct m *next;
    struct m *prev;
}node;

node *list[10], *head[10], *tail[10];

typedef struct integer{
    int sign;
    int deci;
    int len;
}integer;

integer checklist[10];
