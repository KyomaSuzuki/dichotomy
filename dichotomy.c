//二分法のプログラムを作成する
//f(x)の根を求める
//有効数字7桁
#include <stdio.h>
#include <math.h>
#define EPS 1e-7

//f(x)=(x-1)(x-2)(x-3)
double f(double x){
    return (x-1)*(x-2)*(x-3);
}

//二分法
double bisection(double a, double b){
    double c;
    if(f(a)*f(b)>0){
        printf("f(a)とf(b)の符号が同じです\n");
        return NAN;
    }
    while(fabs(b-a)>=EPS){
    
        c=(a+b)/2;
        if(f(c)==0.0) break;
        else if(f(a)*f(c)<0) b=c;
        else a=c;
    }
    return c;
}

int main(){
    double a, b, root;
    printf("aとbを入力してください: ");
    scanf("%lf %lf", &a, &b);
    root=bisection(a, b);
    if(!isnan(root)){
        printf("f(x)=0の解は%.7fです\n", root);
        printf("f(%f)=%.7f\n", root, f(root));
    }
    return 0;
}
