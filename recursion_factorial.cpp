#include <stdio.h>

int factorial(int n){
    printf("%d!는 ",n);
    int i, result = 1;
    for(i=1; i<n; i++){
        result *= i;
    }
    return (result);
}
int main(){
    printf("팩토리얼 계산기입니다. 0보다 큰정수를 입력하세요.\n");
    int number;
    scanf("%d", &number);
    int answer = factorial(number);
    printf("%d!의 계산값은 %d 입니다.", number, answer);
    return 0;
}