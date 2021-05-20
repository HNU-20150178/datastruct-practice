#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s){
    s->top = -1;
}


int is_empty(StackType *s){                 // 모든 연산은 구조체의 포인터를 받는다.
    return (s->top == -1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1)); //1이면 full
}

void push(StackType *s, element item){
    if(is_full(s)){
        printf("Error,Stack is already full\n");
    }else{
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s){
    if(is_empty(s)){
        printf("Error, Stack is already empty\n");
        exit(1);
    }else{
        return s->data[(s->top)--];
    }
}

int main(){
    int value = 6;
    
}

