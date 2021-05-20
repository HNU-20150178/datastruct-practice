#include <stdio.h>

//막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용하여 막대 to로 옮긴다.
void hannoi_tower(int n, char from, char tmp, char to){
    if( n == 1) printf("원반 1을 %c에서 %c으로 옮긴다.\n", from, to);
    else if(n >= 1){
        hannoi_tower(n-1, from, to , tmp);
        printf("원반 %d를 %c에서 %c으로 옮긴다.\n", n, from, to);
        hannoi_tower(n-1, from, to , tmp);
    }
}
int main(){
    hannoi_tower(3,'a','b','c');
}