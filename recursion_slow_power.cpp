#include <stdio.h>
int slow_power(double x, int n){
    int i;
    int result = x;
    for(i=0; i<n; i++){
        result *= x;
    }
    return result;
}
int main(){
    int n,x;
    scanf("%d %d",&x ,&n);
    printf("%d의 %d 제곱의 결과값은 %d입니다", x, n, slow_power(x,n));
    return 0;

}