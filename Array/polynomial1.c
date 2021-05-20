#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(B)) // 조건문//참일떄 리턴됨//거짓을 리턴됨의 형식
#define MAX_DEGREE 101

typedef struct{
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B){
    polynomial result;
    result.degree = (A.degree,B.degree); 
    int Apos = 0, Bpos = 0, Result_pos = 0; // 배열 인덱스 변수 
    int degree_a = A.degree, degree_b = B.degree;
    while(Apos <= A.degree && Bpos <= B.degree){
        if(A.degree > B.degree){
            result.coef[Result_pos++] = A.coef[Apos++];
            degree_a--;
        }else if(degree_a == degree_b){
            result.coef[Result_pos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b;
        }else{ // B항 > A항
            result.coef[Result_pos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return result;
}

void print_poly(polynomial p){
    for(int i = 0; i<p.degree; i++){
        printf("%3.1fx^%d + ", p.coef[p.degree-i],i);
    }
    printf("%3.1f\n", p.coef[p.degree]);


}

int main(){
    polynomial a = { 5, {3, 6, 0, 0, 0, 10 } };
    polynomial b = { 4, {7, 0, 5, 0, 1} };

    print_poly(a);
    print_poly(b);
    polynomial c = poly_add1(a,b);
    printf("------------------------------------------\n");
    print_poly(c);
    return 0;
}