#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message){
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(QueueType *q){
    q->rear = -1;
    q->front = -1;
}
void queue_print(QueueType *q){
    for(int i = 0; i<MAX_QUEUE_SIZE; i++){
        if(i<=q->front || i > q->rear)
            printf(" | ");
        else
            printf("%d | ", q->data[i]);
        
    }
        printf("\n");
}

int is_full(QueueType *q){
    return(q->rear == MAX_QUEUE_SIZE - 1);
}

int is_empty(QueueType *q){
    return(q->front == q-> rear);
}

void enque(QueueType *q, int item){
    if(is_full(q)){
        error("큐가 가득 찼습니다.");
        return;
    }else
        q->data[++(q->rear)] = item;
}

int deque(QueueType *q){
    if(is_empty(q)){
        error("큐가 비었습니다.");
        return -1;
    }else{
        int item = q->data[++(q->front)];
        return item;
    }
}

int main(void){
    int item = 0;
    QueueType myQue;

    init_queue(&myQue);

    enque(&myQue, 10);
    enque(&myQue, 20);

    printf("%d\n",deque(&myQue));
    printf("%d\n",deque(&myQue));
}
