#include<stdio.h>
int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else return n*fact(n-1);
}
int main(){
    int n;
    printf("Enetr n: ");
    scanf("%d",&n);
  int  res= fact(n);
    printf("factorial of %d is: %d",n,res);

    return 0;
}