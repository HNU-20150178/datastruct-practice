#include <stdio.h>

int main(){
    int a = 10;
    int *pointer; // * 역참조 연산자
    pointer = &a; // &  주소 연산자



    printf("%d\n", a); // 원래 a를 그냥 출력
    printf("%d\n", *pointer); // 
    printf("%d\n",&a); // 주소
    printf("%d\n", pointer); // pointer가 가지고 있는 값 (주소)
    printf("%d", &pointer);
    return 0;
}