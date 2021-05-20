#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 20
typedef int element;                        //6~10에서 스택이 구조체로 정의된다.
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
    int popped_integer;
    if(is_empty(s)){
        printf("Error, Stack is already empty\n");
        exit(1);
    }else{
        return s->data[(s->top)--];
    }
}

int main(void){
    StackType s;                //스택을 정적으로 생성한다

    init_stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);                 //함수를 호출할 떄 스택의 주소를 전달한다.
    
    printf("%d", pop(&s));
    printf("%d", pop(&s));
    printf("%d", pop(&s));

    return 0;
}

