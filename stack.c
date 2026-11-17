#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdio.h>
#include "stack.h"

void CreateStack(Stack *s) {
    s->top = -1;
}

int StackEmpty(Stack *s) {
    return (s->top == -1);
}

int StackFull(Stack *s) {
    return (s->top == MAX - 1);
}

void Push(StackEntry item, Stack *s) {
    if (!StackFull(s)) {
        s->top++;
        s->entry[s->top] = item;
    }
}

void Pop(StackEntry *item, Stack *s) {
    if (!StackEmpty(s)) {
        *item = s->entry[s->top];
        s->top--;
    }
}


// Question 14

void splitStack(Stack *ids, Stack *sections, Stack *groups) {
    Stack temp;
    StackEntry id;


    CreateStack(&temp);
    CreateStack(sections);
    CreateStack(groups);

    while (!StackEmpty(ids)) {
        Pop(&id, ids);
        Push(id, &temp);
    }

    while (!StackEmpty(&temp)) {
        Pop(&id, &temp);

        Push(id, ids);
        Push(id / 10, sections);
        Push(id % 10, groups);
    }
}
