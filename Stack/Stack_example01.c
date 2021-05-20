#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//대,중,소 괄호 검사 프로그램
#define MAX_STACK_SIZE 101

typedef char element;
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

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for(i = 0; i< n; i++){  
        ch=in[i];
        switch(ch){
            case '(': case '[': case '{':
            push(&s, ch);
            break;

            case ')': case ']': case '}':
            if(is_empty(&s)) return 0;
            else{
                open_ch = pop(&s);
                if((open_ch == '(' && ch != ')') ||
                (open_ch == '[' && ch != ']') ||
                (open_ch == '{' && ch != '}')){
                    return 0;
                }
            }
            break;
        }
    }
    if(!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1;
}

int main(){
    char *p = "{ A[(i+1)] = 0;}";
    if(check_matching(p)==1){
        printf("%s 괄호검사 성공\n",p);
    }else{
        printf("%s 괄호검사 실패\n",p);
    }
    return 0;
}



