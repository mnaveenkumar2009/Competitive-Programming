#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if(n==2){
            printf("0.5\n");
            continue;
        }
        if(k){
            n+=2*(!(n&1))*((n/2)&1);
        }
        while(k--&&n-1){
            n=(n+1)/2;
        }
        printf("%0.8f\n",1.0/n);
    }
}