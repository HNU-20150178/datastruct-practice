#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 20
typedef struct {
    int student_no;
    char name[MAX_STRING];
    char address[MAX_STRING];
} element;
element Stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
    return (top == -1);
}

int is_full(){
    return (top == (MAX_STACK_SIZE-1)); //1이면 full
}

void push(element item){
    if(is_full()){
        printf("Error,Stack is already full\n");
    }else{
        Stack[++top] = item;
    }
}

element pop(){
    int popped_integer;
    if(is_empty()){
        printf("Error, Stack is already empty\n");
        exit(1);
    }else{
        return(Stack[top--]);
    }
}

int main(void){
    element a = {1,"김진석","창원"};
    element b = {2,"공철환","창원"};
    push(a);
    push(b);

    element i = pop();
    element j = pop();

    
    printf("학번 : %d\n",i.student_no);
    printf("이름 : %s\n",i.name);
    printf("주소 : %s\n",i.address);
    


    return 0;
}

