#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if(k&&(n-2)){
            n+=2*((n&3)==2);
            while(k--*(n-1))
                n=(n+1)/2;
        }
        printf("%0.8f\n",1.0/n);
    }
}