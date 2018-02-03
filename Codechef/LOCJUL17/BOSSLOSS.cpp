    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    int q,i=0,t;
    long long n,m;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%lld%lld",&n,&m);
     
    long double xxx = sqrt(1+8*m);
    xxx-=1.0;
    xxx/=2.0;
    long long h= ceil(xxx);
        if(h<=n)
        printf("%lld\n",h);
        else
        printf("-1\n");
    }
    	return 0;
    }  