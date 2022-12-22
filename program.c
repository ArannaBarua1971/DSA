#include <stdio.h>
long long int num[100000];

void call(int n){

    if(num[n]=='\0') return;
    if(num[n-1]>num[n]) num[n]=num[n-1];
    call(n+1);
}
int main(){
    int n;
    scanf("%d",&n);
    num[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&num[i]);
    }

    call(1);
    for(int i=0;i<n;i++){
        printf("%lld ",num[i]);
    }

}