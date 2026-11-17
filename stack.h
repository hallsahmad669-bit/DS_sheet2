#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX 100

typedef char StackEntry;

typedef struct {
    int top;
    StackEntry entry[MAX];
} Stack;

void CreateStack(Stack *s);
int StackEmpty(Stack *s);
int StackFull(Stack *s);
void Push(StackEntry item, Stack *s);
void Pop(StackEntry *item, Stack *s);
void splitStack(Stack *ids, Stack *sections, Stack *groups);
#endif
